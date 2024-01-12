#include "monty.h"
/**
 * count_tokens - token counter
 * @buffer: string
 *
 * Return: int
 */
int count_tokens(char *buffer)
{
	int count = 0;

	for (int i = 0; buffer[i] != '\0'; i++)
	{
		if (buffer[i] == ' ')
			count++;
	}
	return (count + 1);
}
