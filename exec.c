#include "monty.h"

glob_t glo_var;

/**
 * free_glo_var - frees the global variables
 * Return: no return
 */
void free_glo_var(void)
{
	free_listint(glo_var.head);
	free(glo_var.buffer);
	fclose(glo_var.fd);
}



/**
 * start_glo_var - initializes the global variables
 * @fd: file descriptor
 * Return: no return
 */
void start_glo_var(FILE *fd)
{
	glo_var.lifo = 1;
	glo_var.curr_line = 1;
	glo_var.arg = NULL;
	glo_var.head = NULL;
	glo_var.fd = fd;
	glo_var.buffer = NULL;
}



/**
 * check_input - checks if the file exists
 * and if the file can be opened
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */
FILE *check_input(int argc, char *argv[])
{
	FILE *fd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (fd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *fd;
	size_t size = 256;
	ssize_t nlines = 0;
	char *lines[2] = {NULL, NULL};

	fd = check_input(argc, argv);
	start_glo_var(fd);
	nlines = getline(&glo_var.buffer, &size, fd);
	while (nlines != -1)
	{
		lines[0] = __strtok(glo_var.buffer, " \t\n");
		if (lines[0] && lines[0][0] != '#')
		{
			f = __get_opcodes(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", glo_var.curr_line);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_glo_var();
				exit(EXIT_FAILURE);
			}
			glo_var.arg = __strtok(NULL, " \t\n");
			f(&glo_var.head, glo_var.curr_line);
		}
		nlines = getline(&glo_var.buffer, &size, fd);
		glo_var.curr_line++;
	}

	free_glo_var();

	return (0);
}
