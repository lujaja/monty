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
	if ((!(*stack)->next) || (!(*stack)))
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		free_mem();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
/**
 * nop - function
 * @stack: pointer
 * @line_number: unsigned integer
 *
 * Return: Nothing
 * Description: thi idiot does nothing
 */
void nop(stack_t __attribute__((unused)) **stack, unsigned int __attribute__((unused)) line_number)
{}
/**
 * sub - function
 * @stack: pointer
 * @line_number: unsigned integer
 *
 * Return: Nothing
 * Description: subtract the top element of the stack from the second
 * top element
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (!((*stack)->next) || (!(*stack)))
	{
		dprintf(STDERR_FILENO,"L%u: can't sub, stack too short\n", line_number);
		free_mem();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}
/**
 * div - function
 * @stack: pointer
 * @line_number: unsigned integer
 *
 * Return: Nothing
 * Description: divide the second top element pf the stack by the top element
 * of the stack
 */
void dv(stack_t **stack, unsigned int line_number)
{
	int num;

        if (!((*stack)->next) || (!(*stack)))
        {
                dprintf(STDERR_FILENO,"L%u: can't div, stack too short\n", line_number);
                free_mem();
                exit(EXIT_FAILURE);
        }
	if (((*stack)->n) == 0)
	{
		dprintf(STDERR_FILENO, "L%u: Can't Be Divided by 0\n", line_number);
		free_mem();
		exit(EXIT_FAILURE);
	}
	else
	{
		num = (*stack)->next->n / (*stack)->n;
		(*stack)->next->n = num;
		pop(stack, line_number);
	}
}
/**
 * mul - function
 * @stack: pointer
 * @line_number: size_t integer
 *
 * Return: Nothing
 * Description: multiply the second top element of the stack with the 
 * top element of the stack
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (!((*stack)->next) || (!(*stack)))
	{
		dprintf(STDERR_FILENO, "l%u: can't mul, stack too short\n", line_number);
		free_mem();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
