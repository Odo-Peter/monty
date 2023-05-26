#include "monty.h"

/**
 *__add_nodeint_end - add a node
 * at the end of the doubly link list
 *@head: first position of linked list
 *@n: data to store
 *Return: a doubly linked list
 */
stack_t *__add_nodeint_end(stack_t **head, const int n)
{
	stack_t *temp, *aux;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_glo_var();
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	aux = *head;
	while (aux->next)
		aux = aux->next;
	temp->next = aux->next;
	temp->prev = aux;
	aux->next = temp;
	return (aux->next);
}

/**
 * __add_nodeint - add a node
 * at the begining of the doubly link list
 *@head: first position of linked list
 *@n: data to store
 *Return: a doubly linked list
 */
stack_t *__add_nodeint(stack_t **head, const int n)
{
	stack_t *temp;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(2, "Error: malloc failed\n");
		free_glo_var();
		exit(EXIT_FAILURE);
	}
	temp->n = n;
	if (*head == NULL)
	{
		temp->next = *head;
		temp->prev = NULL;
		*head = temp;
		return (*head);
	}
	(*head)->prev = temp;
	temp->next = (*head);
	temp->prev = NULL;
	*head = temp;
	return (*head);
}

/**
 * free_listint - frees the doubly linked list
 * @head: head of the list
 * Return: no return
 */
void free_listint(stack_t *head)
{
	stack_t *tmp;

	while ((tmp = head) != NULL)
	{
		head = head->next;
		free(tmp);
	}
}
