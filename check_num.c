#include "monty.h"
/**
 * check_num - check if a string is a number
 * @opcode: string to check
 * Return: 1 if true, 0 if false
*/
int check_num(char *opcode)
{
	unsigned int idx = 0;

	if (opcode == NULL)
		return (0);

	while (opcode[idx])
	{
		if (opcode[0] == '-')
		{
			idx++;
			continue;
		}
		if (!isdigit(opcode[idx]))
			return (0);
		idx++;
	}

	return (1);
}
