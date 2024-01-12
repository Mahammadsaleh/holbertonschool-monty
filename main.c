#include "monty.h"
/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	FILE *file_stream = NULL;
	char **token_arr = NULL;
	stack_t *stack = NULL;
	unsigned int line_num = 0;
	size_t len = 0;
	int read;
	char *buffer = NULL;

	args_checker(argc);
	file_stream = f_stream(argv);
	while ((read = getline(&buffer, &len, file_stream)) != -1)
	{
		if (buffer[read - 1] == '\n')
			buffer[read - 1] = '\0';
		token_arr = malloc(sizeof(char *) * 32);
		tokenizer(buffer, token_arr);
		line_num++;
		execute(token_arr, &stack, line_num);
		free_arr(token_arr);
	}
	free(buffer);
	free_stack(&stack);
	fclose(file_stream);
	exit(EXIT_SUCCESS);
}
