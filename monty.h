#ifndef MYHEADER
#define MYHEADER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <ctype.h>
#include <limits.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
FILE *f_stream(char *argv[]);
char **tokenizer(char *buffer, char **token_arr);
void free_arr(char **token_arr);
void args_checker(int argc);
int check_num(char *opcode);
void get_istruction(char *opcode,
		stack_t **cp_stack,
		unsigned int line_number);
void execute(char **token_arr, stack_t **stack, unsigned int line_number);
void s_push(char *opcode, stack_t **stack, unsigned int line_number);
void s_pall(stack_t **sstack, unsigned int __attribute__((unused)) line);
void free_stack(stack_t **stack);
void s_pint(stack_t **stack, unsigned int line);
void s_pop(stack_t **stack, unsigned int line);
void s_nop(stack_t **stack, unsigned int line);
void s_swap(stack_t **stack, unsigned int line);
void s_add(stack_t **stack, unsigned int line);
#endif
