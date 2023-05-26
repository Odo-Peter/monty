#include "monty.h"

/**
 * __fqueue - sets the format of the data to a queue (FIFO)
 *
 * @doubly: head of the linked list
 * @c_line: line number;
 * Return: no return
 */
void __fqueue(stack_t **doubly, unsigned int c_line)
{
	(void)doubly;
	(void)c_line;

	glo_var.lifo = 0;
}


/**
 * __fstack - sets the format fo the data to a stack (LIFO)
 *
 * @doubly: head of the linked list
 * @c_line: line number;
 * Return: no return
 */
void __fstack(stack_t **doubly, unsigned int c_line)
{
	(void)doubly;
	(void)c_line;

	glo_var.lifo = 1;
}


/**
 * __fadd - adds the top two elements of the stack
 *
 * @doubly: head of the linked list
 * @c_line: line number;
 * Return: no return
 */
void __fadd(stack_t **doubly, unsigned int c_line)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", c_line);
		free_glo_var();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n += (*doubly)->n;
	__fpop(doubly, c_line);
}

/**
 * __fnop - does nothing
 *
 * @doubly: head of the linked list
 * @c_line: line number;
 * Return: no return
 */
void __fnop(stack_t **doubly, unsigned int c_line)
{
	(void)doubly;
	(void)c_line;
}


/**
 * __fsub - subtracts the top element to the second top element of the stack
 *
 * @doubly: head of the linked list
 * @c_line: line number;
 * Return: no return
 */
void __fsub(stack_t **doubly, unsigned int c_line)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", c_line);
		free_glo_var();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n -= (*doubly)->n;
	__fpop(doubly, c_line);
}
