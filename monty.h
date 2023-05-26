#ifndef __MONTY_H__
#define __MONTY_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/*Prequisite Data Structures*/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;



/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/*Global data structure*/
/**
 * struct globals_list - structure of global
 * linked list to be used in the functions
 * @lifo: is stack or queue
 * @curr_line: current line
 * @arg: second params inside the current line
 * @head: head of a doubly linked list
 * @fd: file descriptor
 * @buffer: input buffer for text
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct globals_list
{
	int lifo;
	unsigned int curr_line;
	char *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} glob_t;


extern glob_t glo_var;


/*Functions and opcode instructions*/
stack_t *__add_nodeint_end(stack_t **head, const int n);
stack_t *__add_nodeint(stack_t **head, const int n);
void free_listint(stack_t *head);


void __fpush(stack_t **stack, unsigned int c_line);
void __fpall(stack_t **stack, unsigned int c_line);
void __fpint(stack_t **doubly, unsigned int c_line);
void __fpop(stack_t **doubly, unsigned int c_line);
void __fswap(stack_t **doubly, unsigned int c_line);
void __fqueue(stack_t **doubly, unsigned int c_line);
void __fstack(stack_t **doubly, unsigned int c_line);
void __fadd(stack_t **doubly, unsigned int c_line);
void __fnop(stack_t **doubly, unsigned int c_line);
void __fsub(stack_t **doubly, unsigned int c_line);
void __fdiv(stack_t **doubly, unsigned int c_line);
void __fmul(stack_t **doubly, unsigned int c_line);
void __fmod(stack_t **doubly, unsigned int c_line);
void __fpchar(stack_t **doubly, unsigned int c_line);
void __fpstr(stack_t **doubly, unsigned int c_line);
void __frotl(stack_t **doubly, unsigned int c_line);
void __frotr(stack_t **doubly, unsigned int c_line);


void (*__get_opcodes(char *opc))(stack_t **stack, unsigned int line_num);


int __search(char *s, char c);
char *__strtok(char *s, char *d);
void *__realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *__calloc(unsigned int num_el, unsigned int size);
int __strcmp(char *s1, char *s2);

void free_glo_var(void);

#endif
