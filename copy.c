#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
int main(int argc, char *argv[])
{
	FILE *file_stream = NULL;
	int line_num = 0;
	size_t len = 0;
	int read;
	char *buffer = malloc(1024);
char **token_arr = malloc(100 * sizeof(char *));
if (token_arr == NULL) {
    // Handle allocation failure
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
}
	args_checker(argc);
	file_stream = f_stream(argv);
	while ((read = getline(&buffer, &len, file_stream)) != -1)
	{
		if (buffer[read - 1] == '\n')
			buffer[read - 1] = '\0';
		tokenizer(buffer, token_arr);
		line_num++;

	}
for (int i = 0; i < 100 && token_arr[i] != NULL; i++) {
    printf("%s\n", token_arr[i]);
}
	printf("%s", buffer);
	printf("%d", line_num);
	free(buffer);
        fclose(file_stream);
	return (0);
}
