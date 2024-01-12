#include "monty.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * tokenizer - devide the line
 * @buffer: string
 * @token_arr: array
 *
 * Return: char ptr to ptr
 */
char **tokenizer(char *buffer, char **token_arr)
{
	char *token;
	char *delims = " \n\t";
	int i = 0;

	token = strtok(buffer, delims);
	while (token != NULL)
	{
		token_arr[i] = malloc(strlen(token) + 1);
		strcpy(token_arr[i], token);
		i++;
		token = strtok(NULL, delims);
	}
	token_arr[i] = NULL;
	return (token_arr);
}

/**
 * f_stream - file stream
 * @argv: arguments
 *
 * Return: FILE
 */
FILE *f_stream(char *argv[])
{
	FILE *file_stream = NULL;

	file_stream = fopen(argv[1], "r");
	if (file_stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (file_stream);
}
/**
 * free_arr - free array
 * @token_arr: arguments
 *
 * Return: void
 */
void free_arr(char **token_arr)
{
	if (token_arr != NULL)
	{
		for (int i = 0; token_arr[i] != NULL; i++)
		{
			free(token_arr[i]);
		}
		free(token_arr);
	}
}
