#include "monty.h"
void get_istruction(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t function[] = {
		{"pall", s_pall},
		/**{"pint", s_pint},
		{"pop", s_pop},
		{"nop", s_nop},
		{"swap", s_swap},
		{"add", s_add},**/
		{NULL, NULL}
	};
	while (function[i].opcode)
	{
		if (strcmp(function[i].opcode, opcode) == 0)
		{
			function[i].f(stack, line_number);
			break;
		}
		i++;
	}
	if (function[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
void execute(char **token_arr, stack_t **stack, unsigned int line_number)
{
	if (strcmp(token_arr[0], "push") == 0)
	{
		s_push(token_arr[1], stack, line_number);
	}
	else
	{
		get_istruction(token_arr[0], stack, line_number);
	}
}
void free_stack(stack_t **stack)
{
    stack_t *current_node;
    stack_t *next_node;

    current_node = *stack;
    while (current_node != NULL)
    {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
}
