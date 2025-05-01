/* tinydb/main.c – Milestone 0: bootstrap REPL */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INPUT_BUFFER_SIZE 256

int main(void)
{
    char input[INPUT_BUFFER_SIZE];
    while (true) {
        printf("tinydb> ");
        if (!fgets(input, sizeof(input), stdin)) {
            printf("\n"); 
            break;
        }
        size_t len = strlen(input);
        if (len && input[len - 1] == '\n')
            input[len - 1] = '\0';
        if (input[0] == '.') {
            if (strcmp(input, ".exit") == 0) {
                puts("Bye!");
                break;
            }
            printf("Unrecognized meta-command '%s'\n", input);
            continue;
        }
        printf("Unrecognized keyword at start of '%s'\n", input);
    }
    return 0;
}