#include "monty.h"
/**
 * mod - function
 * @stack: pointer
 * @line_number: unsigned integer
 *
 * Return: Nothing
 * Description: computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if ((!(*stack)->next) || (!(*stack)))
	{
		dprintf(STDERR_FILENO, "L%u: can't mod, stack too short\n", line_number);
		free_mem();
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n) == 0)
	{
		dprintf(STDERR_FILENO, "L%u: Result is undefined\n", line_number);
		free_mem();
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack)->next->n %= (*stack)->n;
		pop(stack, line_number);
	}
}
