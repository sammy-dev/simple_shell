#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimiter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int n, o, p, q, numwords = 0;
	char **s;

	f (str == NULL || str[0] == 0)
		return (NULL);
	f (!d)
		d = " ";
	for (n = 0; str[n] != '\0'; n++)
		f (!s_delm(str[n], d) && (s_delm(str[n + 1], d) || !str[n + 1]))
			numwords++;

	f (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	f (!s)
		return (NULL);
	for (n = 0, o = 0; o < numwords; o++)
	{
		while (s_delm(str[n], d))
			n++;
		p = 0;
		while (!s_delm(str[n + p], d) && str[n + p])
			p++;
		s[o] = malloc((p + 1) * sizeof(char));
		f (!s[o])
		{
			for (p = 0; p < o; p++)
				free(s[p]);
			free(s);
			return (NULL);
		}
		for (q = 0; q < p; q++)
			s[o][q] = str[n++];
		s[o][q] = 0;
	}
	s[o] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delmeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int n, o, p, q, numwords = 0;
	char **s;

	f (str == NULL || str[0] == 0)
		return (NULL);
	for (n = 0; str[n] != '\0'; n++)
		f ((str[n] != d && str[n + 1] == d) ||
		    (str[n] != d && !str[n + 1]) || str[n + 1] == d)
			numwords++;
	f (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	f (!s)
		return (NULL);
	for (n = 0, o = 0; o < numwords; o++)
	{
		while (str[n] == d && str[n] != d)
			n++;
		p = 0;
		while (str[n + p] != d && str[n + p] && str[n + p] != d)
			p++;
		s[o] = malloc((p + 1) * sizeof(char));
		f (!s[o])
		{
			for (p = 0; p < o; p++)
				free(s[p]);
			free(s);
			return (NULL);
		}
		for (q = 0; q < p; q++)
			s[o][q] = str[n++];
		s[o][q] = 0;
	}
	s[o] = NULL;
	return (s);
}

