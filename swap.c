#include "monty.h"

/**
 * s_swap - swaps the top two nodes of the stack
 * @stack: nodes
 * @line_number: file line number
 */

void s_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	stack_t *aux = *stack;

	if (!*stack || !stack || !head->next)
	{
		dprintf(STDERR_FILENO, "L%i: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	head = head->next;
	head->prev = NULL;

	aux->next = head->next;
	head->next = aux;
	(head->next)->prev = head;

	*stack = head;
}
