#include "monty.h"
/**
 * __calloc - concatenate two strings specially
 * @num_el: number of elements
 * @size: type of elements
 * Return: nothing
 */
void *__calloc(unsigned int num_el, unsigned int size)
{
	void *p = NULL;
	unsigned int i;

	if (num_el == 0 || size == 0)
	{
		return (NULL);
	}
	p = malloc(num_el * size);
	if (p == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < (num_el * size); i++)
	{
		*((char *)(p) + i) = 0;
	}
	return (p);
}
/**
 * __realloc - change the size and copy the content
 * @ptr: malloc pointer to reallocate
 * @old_size: old number of bytes
 * @new_size: new number of Bytes
 * Return: nothing
 */
void *__realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p = NULL;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		return (p);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (new_size > old_size)
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		for (i = 0; i < old_size; i++)
			p[i] = *((char *)ptr + i);
		free(ptr);
	}
	else
	{
		p = malloc(new_size);
		if (!p)
			return (NULL);
		for (i = 0; i < new_size; i++)
			p[i] = *((char *)ptr + i);
		free(ptr);
	}
	return (p);
}
