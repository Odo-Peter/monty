#include "monty.h"

/**
 * __frotl - rotates the first element to the bottom
 * and the second to the top
 * @doubly: head of the linked list
 * @c_line: line number;
 * Return: no return
 */
void __frotl(stack_t **doubly, unsigned int c_line)
{
	stack_t *aux1 = NULL;
	stack_t *aux2 = NULL;
	(void)c_line;

	if (*doubly == NULL)
		return;

	if ((*doubly)->next == NULL)
		return;

	aux1 = (*doubly)->next;
	aux2 = *doubly;

	for (; aux2->next != NULL; aux2 = aux2->next)
		;

	aux1->prev = NULL;
	aux2->next = *doubly;
	(*doubly)->next = NULL;
	(*doubly)->prev = aux2;
	*doubly = aux1;
}



/**
 * __frotr - reverse the stack
 * @doubly: head of the linked list
 * @c_line: line number
 * Return: no return
 */
void __frotr(stack_t **doubly, unsigned int c_line)
{
	stack_t *aux = NULL;
	(void)c_line;

	if (*doubly == NULL)
		return;

	if ((*doubly)->next == NULL)
		return;

	aux = *doubly;

	for (; aux->next != NULL; aux = aux->next)
		;

	aux->prev->next = NULL;
	aux->next = *doubly;
	aux->prev = NULL;
	(*doubly)->prev = aux;
	*doubly = aux;
}
