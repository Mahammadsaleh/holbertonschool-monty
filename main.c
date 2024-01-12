#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *file_stream = NULL;
	char **token_arr = NULL;
	int line_num = 0;
	size_t len = 0;
	int read;
	char *buffer = malloc(128);

	args_checker(argc);
	file_stream = f_stream(argv);
	while ((read = getline(&buffer, &len, file_stream)) != -1)
	{
		if (buffer[read - 1] == '\n')
			buffer[read - 1] = '\0';
		token_arr = malloc(sizeof(char*) * 1024);
		tokenizer(buffer, token_arr);
		line_num++;
		if (token_arr != NULL)
		{
			for (int i = 0; token_arr[i] != NULL; i++)
			{
				printf("%s\n", token_arr[i]);
			}
		}
		if (token_arr != NULL)
		{
			for (int i = 0; token_arr[i] != NULL; i++)
			{
				free(token_arr[i]);
			}
			free(token_arr);
		}
	}
	free(buffer);
	free(token_arr);
	fclose(file_stream);
	return 0;
}
