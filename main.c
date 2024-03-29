#include "monty.h"
int count_tokens(char *buffer);
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
	int read, token_count;
	char *buffer = NULL;

	args_checker(argc);
	file_stream = f_stream(argv);
	while ((read = getline(&buffer, &len, file_stream)) != -1)
	{
		if (buffer[read - 1] == '\n')
			buffer[read - 1] = '\0';
		if (buffer[0] == '\0')
		{
			++line_num;
			continue;
		}
		++line_num;
		token_count = count_tokens(buffer);
		token_arr = malloc(sizeof(char *) * (token_count + 1));
		tokenizer(buffer, token_arr);
		if (token_arr[0] != NULL)
		{
			execute(token_arr, &stack, line_num);
		}
		free_arr(token_arr);
	}
	free(buffer);
	free_stack(&stack);
	fclose(file_stream);
	exit(EXIT_SUCCESS);
}
