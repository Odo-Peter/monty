#include "monty.h"

/**
 * __fdiv - divides the second element by the top element of the stack
 *
 * @doubly: head of the linked list
 * @c_line: line number;
 * Return: no return
 */
void __fdiv(stack_t **doubly, unsigned int c_line)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't div, stack too short\n", c_line);
		free_glo_var();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", c_line);
		free_glo_var();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n /= (*doubly)->n;
	__fpop(doubly, c_line);
}


/**
 * __fmul - multiplies the top element to the second top element of the stack
 *
 * @doubly: head of the linked list
 * @c_line: line number;
 * Return: no return
 */
void __fmul(stack_t **doubly, unsigned int c_line)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", c_line);
		free_glo_var();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n *= (*doubly)->n;
	__fpop(doubly, c_line);
}

/**
 * __fmod - computes the rest of the
 * division of the second element
 * by the top element of the stack
 * @doubly: head of the linked list
 * @c_line: line number;
 * Return: no return
 */
void __fmod(stack_t **doubly, unsigned int c_line)
{
	int m = 0;
	stack_t *aux = NULL;

	aux = *doubly;

	for (; aux != NULL; aux = aux->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", c_line);
		free_glo_var();
		exit(EXIT_FAILURE);
	}

	if ((*doubly)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", c_line);
		free_glo_var();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n %= (*doubly)->n;
	_pop(doubly, cline);
}



/**
 * __fpchar - print the char value of the first element
 * @doubly: head of the linked list
 * @c_line: line number;
 * Return: no return
 */
void __fpchar(stack_t **doubly, unsigned int c_line)
{
	if (doubly == NULL || *doubly == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", c_line);
		free_glo_var();
		exit(EXIT_FAILURE);
	}
	if ((*doubly)->n < 0 || (*doubly)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", c_line);
		free_glo_var();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*doubly)->n);
}



/**
 * __fpstr - prints the string of the stack
 * @doubly: head of the linked list
 * @c_line: line number;
 * Return: no return
 */
void __fpstr(stack_t **doubly, unsigned int c_line)
{
	stack_t *aux;
	(void)c_line;

	aux = *doubly;

	while (aux && aux->n > 0 && aux->n < 128)
	{
		printf("%c", aux->n);
		aux = aux->next;
	}

	printf("\n");
}
