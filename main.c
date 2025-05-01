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
            printf("\n");      /* handle Ctrl-D */
            break;
        }

        /* Strip trailing newline */
        size_t len = strlen(input);
        if (len && input[len - 1] == '\n')
            input[len - 1] = '\0';

        /* Meta-commands start with a dot */
        if (input[0] == '.') {
            if (strcmp(input, ".exit") == 0) {
                puts("Bye!");
                break;
            }
            printf("Unrecognized meta-command '%s'\n", input);
            continue;
        }

        /* Placeholder for SQL-like statements */
        printf("Unrecognized keyword at start of '%s'\n", input);
    }
    return 0;
}