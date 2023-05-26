#include "monty.h"

/**
 * __fpush - pushes an element to the stack
 *
 * @doubly: head of the linked list
 * @c_line: line number
 * Return: void function
 */
void __fpush(stack_t **doubly, unsigned int c_line)
{
	int n, j;

	if (!glo_var.arg)
	{
		dprintf(2, "L%u: ", c_line);
		dprintf(2, "usage: push integer\n");
		free_glo_var();
		exit(EXIT_FAILURE);
	}

	for (j = 0; glo_var.arg[j] != '\0'; j++)
	{
		if (!isdigit(glo_var.arg[j]) && glo_var.arg[j] != '-')
		{
			dprintf(2, "L%u: ", c_line);
			dprintf(2, "usage: push integer\n");
			free_glo_var();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(glo_var.arg);

	if (glo_var.lifo == 1)
		__add_nodeint(doubly, n);
	else
		__add_nodeint_end(doubly, n);
}

/**
 * __fpall - prints all values on the stack
 *
 * @doubly: head of the linked list
 * @c_line: line numbers
 * Return: no return
 */
void __fpall(stack_t **doubly, unsigned int c_line)
{
	stack_t *aux;
	(void)c_line;

	aux = *doubly;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * __fpint - prints the value at the top of the stack
 *
 * @doubly: head of the linked list
 * @c_line: line number
 * Return: no return
 */
void __fpint(stack_t **doubly, unsigned int c_line)
{
	(void)c_line;

	if (*doubly == NULL)
	{
		dprintf(2, "L%u: ", c_line);
		dprintf(2, "can't pint, stack empty\n");
		free_glo_var();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*doubly)->n);
}

/**
 * __fpop - removes the top element of the stack
 *
 * @doubly: head of the linked list
 * @c_line: line number
 * Return: no return
 */
void __fpop(stack_t **doubly, unsigned int c_line)
{
	stack_t *aux;

	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", c_line);
		free_glo_var();
		exit(EXIT_FAILURE);
	}
	aux = *doubly;
	*doubly = (*doubly)->next;
	free(aux);
}

/**
 * __fswap - swaps the top two elements of the stack
 *
 * @doubly: head of the linked list
 * @c_line: line number
 * Return: no return
 */
void __fswap(stack_t **doubly, unsigned int c_line)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", c_line);
		free_glo_var();
		exit(EXIT_FAILURE);
	}

	aux = *doubly;
	*doubly = (*doubly)->next;
	aux->next = (*doubly)->next;
	aux->prev = *doubly;
	(*doubly)->next = aux;
	(*doubly)->prev = NULL;
}
