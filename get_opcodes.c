#include "monty.h"

/**
 * __get_opcodes - selects the correct opcode
 * to perform an operation on it
 * @opc: opcode being passed
 * Return: pointer to the function that executes the opcode
 */
void (*__get_opcodes(char *opc))(stack_t **stack, unsigned int line_num)
{
	instruction_t instruct[] = {
		{"push", __fpush},
		{"pall", __fpall},
		{"pint", __fpint},
		{"pop", __fpop},
		{"swap", __fswap},
		{"queue", __fqueue},
		{"stack", __fstack},
		{"add", __fadd},
		{"nop", __fnop},
		{"sub", __fsub},
		{"mul", __fmul},
		{"div", __fdiv},
		{"mod", __fmod},
		{"pchar", __fpchar},
		{"pstr", __fpstr},
		{"rotl", __frotl},
		{"rotr", __frotr},
		{NULL, NULL}};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (__strcmp(instruct[i].opcode, opc) == 0)
			break;
	}

	return (instruct[i].f);
}
