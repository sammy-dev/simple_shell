#include "shell.h"

/**
 * custom_strncpy - copies a string
 * @destination: the destination string to be copied to
 * @source: the source string
 * @n: the amount of characters to be copied
 * Return: the concatenated string
 */
char *custom_strncpy(char *destination, char *source, int n)
{
    int index_dest = 0, index_src = 0;
    char *result = destination;

    while (source[index_src] != '\0' && index_dest < n - 1)
    {
        destination[index_dest] = source[index_src];
        index_dest++;
        index_src++;
    }
    if (index_dest < n)
    {
        int j = index_dest;
        while (j < n)
        {
            destination[j] = '\0';
            j++;
        }
    }
    return result;
}

/**
 * custom_strncat - concatenates two strings
 * @destination: the first string
 * @source: the second string
 * @n: the amount of bytes to be maximally used
 * Return: the concatenated string
 */
char *custom_strncat(char *destination, char *source, int n)
{
    int index_dest = 0, index_src = 0;
    char *result = destination;

    while (destination[index_dest] != '\0')
        index_dest++;
    while (source[index_src] != '\0' && index_src < n)
    {
        destination[index_dest] = source[index_src];
        index_dest++;
        index_src++;
    }
    if (index_src < n)
        destination[index_dest] = '\0';
    return result;
}

/**
 * custom_strchr - locates a character in a string
 * @string: the string to be parsed
 * @character: the character to look for
 * Return: (string) a pointer to the memory area string
 */
char *custom_strchr(char *string, char character)
{
    do
    {
        if (*string == character)
            return string;
    } while (*string++ != '\0');

    return NULL;
}
