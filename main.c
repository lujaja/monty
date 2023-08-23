#include "monty.h"

g_var g_vr;

/**
 * main - entry point
 * @c: argument count
 * @v: argument list
 *
 * Return: 0 always success
 * Description: base program
 */
int main(int c, char **v)
{
	char *opcode;

	if (c != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (initializer(&g_vr) != 0)
		return (EXIT_FAILURE);

	g_vr.fd = fopen(v[1], "r");
	if (g_vr.fd == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", v[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&g_vr.buffer, &g_vr.status, g_vr.fd) != EOF)
	{
		opcode = strtok(g_vr.buffer, "\r\t\n");
		if (opcode != NULL)
			if (check_func(opcode, &g_vr.head, g_vr.line_number) == EXIT_FAILURE)
			{
				free_mem();
				exit(EXIT_FAILURE);
			}
		g_vr.line_number++;
	}

	free_mem();

	return (EXIT_SUCCESS);
}
