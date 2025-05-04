#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INPUT_BUFFER_SIZE 256  // Max size for user input
// Enum to represent supported statement types
typedef enum {
    INSERT,
    SELECT,
    IDK  // Unknown or unrecognized command
} Statement;
// Structure representing a single row in the table
typedef struct {
    unsigned int id;
    char username[32];
    char email[255];
} Row;
// Fixed-size table (static array) to store rows
Row table[200];
size_t count = 0;  // Current number of rows in the table
// Simple parser to determine the type of statement from input
Statement parser(const char* input) {
    if (strncmp(input, "insert", 6) == 0) {
        return INSERT;
    } else if (strncmp(input, "select", 6) == 0) {
        return SELECT;
    } else {
        return IDK;
    }
}
int main(void) {
    char input[INPUT_BUFFER_SIZE];

    while (true) {
        printf("tinydb> ");
        // Read input from stdin
        if (!fgets(input, sizeof(input), stdin)) {
            printf("\n");  // Handle EOF with newline
            break;
        }
        // Remove newline character from input
        size_t len = strlen(input);
        if ((len != 0) && (input[len - 1] == '\n'))
            input[len - 1] = '\0';
        // Handle meta-commands (starting with '.')
        if (input[0] == '.') {
            if (strcmp(input, ".exit") == 0) {
                puts("Bye!");
                break;
            } else if (strcmp(input, ".help") == 0) {
                printf("Available commands:\n .exit    Exit the data base\n .help    Show this help message\n");
                continue;
            }
        }
        // Parse the command type (INSERT, SELECT, or IDK)
        Statement curr = parser(input);
        if (curr == INSERT) {
            puts("Insert recogonized");
            continue;
        } else if (curr == SELECT) {
            puts("Select recogonized");
            continue;
        }
        // If not recognized, print error message
        printf("Unrecognized keyword at start of '%s'\n", input);
    }
    return 0;
}