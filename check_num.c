#include "monty.h"
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
