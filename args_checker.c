#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * args_checker - Check args count
 * @argc: arguments count
 */
void args_checker(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}
