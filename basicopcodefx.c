#include "monty.h"
/**
 * pall - prints all values on stack
 * @stack: pointer pointer to stack
 * @line_number: absolute integer
 *
 * Return: Nothing
 * Description: prints values on stack starting from the top of the stack
 */
void pall(stack_t **stack, unsigned int __attribute__((unused)) line_number)
{
	stack_t *temp;

	temp = *stack;
	if (!temp)
	{
		dprintf(STDERR_FILENO, "Error: stack empty\n");
		free_mem();
		exit(EXIT_FAILURE);
	}

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * push - functio
 * @stack: pointer pointer
 * @line_number: absolute integer
 *
 * Return: Nothing
 * Description: push opcode function
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *token;
	int num;
	stack_t *temp, *tmp;
	
	token = strtok(NULL, " ");
	tmp = *stack;
	if (!token || (_isdigit(token) != 0 && token[0] != '-'))
	{
		dprintf(STDERR_FILENO, "L%u: Usage: push integer\n", line_number);
		free_mem();
		exit(EXIT_FAILURE);
	}
	num = atoi(token);
	temp = (stack_t *) malloc(sizeof(stack_t));
	if (!temp)
	{
		dprintf(STDERR_FILENO, "Error: malloc failure\n");
		free_mem();
		exit(EXIT_FAILURE);
	}
	temp->n = num;
	temp->next = NULL;
	temp->prev = NULL;
	if (g_vr.M == 0 || !tmp)
	{
		temp->next = *stack;
		if (*stack)
			(*stack)->prev = temp;
		*stack = temp;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = temp;
		temp->prev = tmp;
		temp->next = NULL;
	}
}
/**
 * pint - function
 * @stack: pointer pointer to head node
 * @line_number: size_t integer
 *
 * Return: Nothing
 * Description: print the value at top
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		dprintf(STDERR_FILENO,"L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop - function
 * @stack: pointer to head dnode
 * @line_number: size_t integer
 *
 * Return: Nothing
 * Description: remove the value at top of stack
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		free_mem();
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = temp->next;
	if (temp->next)
		temp->next->prev = NULL;
	free(temp);
}
/**
 * swap - function
 * @stack: pointer
 * @line_number: size_t integer
 *
 * Return: Nothing
 * Description: swap the first two element on stack
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int n;

	if ((!(*stack)->next) || (!(stack)))
	{
		dprintf(STDERR_FILENO, "L%u: cant swap, stack too short\n", line_number);
		free_mem();
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	n = temp->n;
	temp->n = temp->next->n;
	temp->next->n = n;
}
