#include "monty.h"

/**
 * __strcmp - Function that compares two strings.
 * @s1: type str compared
 * @s2: type str compared
 * Return: 0 if s1 and s2 are equals.
 * another value if they are different
 */
int __strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] == s2[i] && s1[i]; i++)
		;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}


/**
 * __search - search if a char is inside a string
 * @s: string to review
 * @c: char to find
 * Return: 1 if success 0 if not
 */
int __search(char *s, char c)
{
	int t = 0;

	while (s[t] != '\0')
	{
		if (s[t] == c)
		{
			break;
		}
		t++;
	}
	if (s[t] == c)
		return (1);
	else
		return (0);
}

/**
 * __strtok - splits a string into tokens depending on the delimit
 * @s: string to cut in parts
 * @d: delimiters
 * Return: first partition
 */
char *__strtok(char *s, char *d)
{
	static char *u;
	int i = 0, j = 0;

	if (!s)
		s = u;
	while (s[i] != '\0')
	{
		if (__search(d, s[i]) == 0 && s[i + 1] == '\0')
		{
			u = s + i + 1;
			*u = '\0';
			s = s + j;
			return (s);
		}
		else if (__search(d, s[i]) == 0 && __search(d, s[i + 1]) == 0)
			i++;
		else if (__search(d, s[i]) == 0 && __search(d, s[i + 1]) == 1)
		{
			u = s + i + 1;
			*u = '\0';
			u++;
			s = s + j;
			return (s);
		}
		else if (__search(d, s[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
