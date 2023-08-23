#include "monty.h"
/**
 * add - function
 * @stack: pointer
 * @line_number: size_t integer
 *
 * Return: Nothing
 * Description: add top two elements of stack
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if ((!(*stack)->next))
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		free_mem();
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = temp->next;
	(*stack)->n += temp->n;
	if (temp->next)
		temp->next->prev = NULL;
	free(temp);
}
/**
 * nop - function
 * @stack: pointer
 * @line_number: size_t integer
 *
 * Return: Nothing
 * Description: this idiot does nothing
 */
void nop(stack_t __attribute__((unused)) **stack, unsigned int __attribute__((unused)) line_number)
{}
