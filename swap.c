#include "monty.h"

/**
 * s_swap - swaps the top two nodes of the stack
 * @stack: nodes
 * @line_number: file line number
 */

void s_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack || !stack || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%i: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}
