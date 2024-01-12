#include "monty.h"
/**
 * get_istruction - execute the command
 * @opcode: opcode to get
 * @stack: stack to use
 * @line_number: line of the opcode
 * Return: void
*/
void get_istruction(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i = 0;

	instruction_t function[] = {
		{"pall", s_pall},
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
/**
 * execute - execute the command
 * @token_arr: opcode to get
 * @stack: stack to use
 * @line_number: line of the opcode
 * Return: void
*/
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
/**
 * free_stack - free a stack
 * @stack: head of the stack
 * Return: void
*/
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
