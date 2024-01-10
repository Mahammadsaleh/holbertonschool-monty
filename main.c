#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

int main(int argc, char *argv[]) {
    FILE *file_stream = NULL;
    char **token_arr = NULL; // Initialize token_arr to NULL
    int line_num = 0;
    size_t len = 0;
    int read;
    char *buffer = malloc(1024);

    args_checker(argc);
    file_stream = f_stream(argv);
    while ((read = getline(&buffer, &len, file_stream)) != -1) {
        if (buffer[read - 1] == '\n')
            buffer[read - 1] = '\0';
        token_arr = malloc(sizeof(char*) * 1024); // Allocate memory for token_arr
        tokenizer(buffer, &token_arr); // Pass the address of token_arr to tokenizer
        line_num++;

        // Print all strings in token_arr
        if (token_arr != NULL) {
            for (int i = 0; token_arr[i] != NULL; i++) {
                printf("%s\n", token_arr[i]);
            }
        }

        // Free memory allocated for tokens
        if (token_arr != NULL) {
            for (int i = 0; token_arr[i] != NULL; i++) {
                free(token_arr[i]);
            }
            free(token_arr);
        }
    }

    printf("%d\n", line_num);

    free(buffer);
    fclose(file_stream);
    return 0;
}
