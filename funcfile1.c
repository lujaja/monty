#include "monty.h"
/**
 * check_func - function pointer
 * @opcode: pointer
 * @stack: pointer
 * @line_number: integer
 *
 * Return: function
 * Description: check for required function for given opcode
 */
int  check_func(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t op_code[] = {
		{"pall", pall},
		{"push", push},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	char *operation;
	int i;

	i = 0;
	operation = strtok(opcode, " ");

	while (operation)
	{
		while (op_code[i].opcode)
		{
			if ((strcmp(op_code[i].opcode, operation)) == 0)
			{
				op_code[i].f(stack, line_number);
			}
			if ((op_code[i].opcode) == NULL)
				return (EXIT_FAILURE);
			i++;
		}
		operation = strtok(NULL, " ");
	}
	return (EXIT_SUCCESS);
}
/**
 * _isdigit - function
 * @str: character pointer
 *
 * Return: 0 success or 1 failure
 * Description: check if a string is an integer
 */
int _isdigit(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] < 48 || str[i] > 58)
			return (1);
	}
	return (0);
}
/**
 * free_mem - function
 *
 * Return: Nothing
 * Description: free function
 */
void free_mem(void)
{
	if (g_vr.buffer)
		free(g_vr.buffer);

	if (g_vr.fd)
		fclose(g_vr.fd);

	if (g_vr.head)
	{
		while (g_vr.head->next)
		{
			g_vr.head = g_vr.head->next;
			free(g_vr.head->prev);
		}
		free(g_vr.head);
	}
}
