#include "shell.h"

/**
 * buffer_input - buffers chained commands
 * @info: parameter struct
 * @commandBuffer: address of command buffer
 * @bufferSize: address of buffer size variable
 *
 * Return: bytes read
 */
ssize_t buffer_input(info_t *info, char **commandBuffer, size_t *bufferSize)
{
	ssize_t bytesRead = 0;
	size_t bufferLength = 0;

	if (!*bufferSize) /* if nothing left in the buffer, fill it */
	{
		free(*commandBuffer);
		*commandBuffer = NULL;
		signal(SIGINT, sigintHandler);

#if USE_GETLINE
		bytesRead = getline(commandBuffer, &bufferLength, stdin);
#else
		bytesRead = custom_getline(info, commandBuffer, &bufferLength);
#endif

		if (bytesRead > 0)
		{
			if ((*commandBuffer)[bytesRead - 1] == '\n')
			{
				(*commandBuffer)[bytesRead - 1] = '\0'; /* remove trailing newline */
				bytesRead--;
			}
			info->linecount_flag = 1;
			remove_comments(*commandBuffer);
			build_history_list(info, *commandBuffer, info->histcount++);

			{
				*bufferSize = bytesRead;
				info->cmd_buf = commandBuffer;
			}
		}
	}
	return bytesRead;
}

/**
 * get_user_input - gets a line minus the newline
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_user_input(info_t *info)
{
	static char *commandBuffer; /* the ';' command chain buffer */
	static size_t bufferIndex, bufferLength;
	ssize_t bytesRead = 0;
	char **bufferPointer = &(info->arg), *currentPosition;

	_putchar(BUF_FLUSH);
	bytesRead = buffer_input(info, &commandBuffer, &bufferLength);
	if (bytesRead == -1) /* EOF */
		return -1;
	if (bufferLength) /* we have commands left in the chain buffer */
	{
		bufferIndex = bufferIndex;
		currentPosition = commandBuffer + bufferIndex;

		check_chain(info, commandBuffer, &bufferIndex, bufferIndex, bufferLength);
		while (bufferIndex < bufferLength)
		{
			if (is_chain(info, commandBuffer, &bufferIndex))
				break;
			bufferIndex++;
		}

		bufferIndex = bufferIndex + 1;
		if (bufferIndex >= bufferLength)
		{
			bufferIndex = bufferLength = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*bufferPointer = currentPosition;
		return _strlen(currentPosition);
	}

	*bufferPointer = commandBuffer;
	return bytesRead;
}

/**
 * read_buffer - reads a buffer
 * @info: parameter struct
 * @buffer: buffer
 * @index: size
 *
 * Return: bytesRead
 */
ssize_t read_buffer(info_t *info, char *buffer, size_t *index)
{
	ssize_t bytesRead = 0;

	if (*index)
		return 0;
	bytesRead = read(info->readfd, buffer, READ_BUF_SIZE);
	if (bytesRead >= 0)
		*index = bytesRead;
	return bytesRead;
}

/**
 * custom_getline - gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: bytesRead
 */
int custom_getline(info_t *info, char **ptr, size_t *length)
{
	static char buffer[READ_BUF_SIZE];
	static size_t bufferIndex, bufferLength;
	size_t k;
	ssize_t bytesRead = 0, totalBytesRead = 0;
	char *currentPosition = NULL, *newPosition = NULL, *c;

	currentPosition = *ptr;
	if (currentPosition && length)
		totalBytesRead = *length;
	if (bufferIndex == bufferLength)
		bufferIndex = bufferLength = 0;

	bytesRead = read_buffer(info, buffer, &bufferLength);
	if (bytesRead == -1 || (bytesRead == 0 && bufferLength == 0))
		return -1;

	c = _strchr(buffer + bufferIndex, '\n');
	k = c ? 1 + (unsigned int)(c - buffer) : bufferLength;
	newPosition = _realloc(currentPosition, totalBytesRead, totalBytesRead ? totalBytesRead + k : k + 1);

	if (!newPosition) /* MALLOC FAILURE! */
		return (currentPosition ? free(currentPosition), -1 : -1);

	if (totalBytesRead)
		_strncat(newPosition, buffer + bufferIndex, k - bufferIndex);
	else
		_strncpy(newPosition, buffer + bufferIndex, k - bufferIndex + 1);

	totalBytesRead += k - bufferIndex;
	bufferIndex = k;
	currentPosition = newPosition;

	if (length)
		*length = totalBytesRead;
	*ptr = currentPosition;
	return totalBytesRead;
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
