#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INPUT_BUFFER_SIZE 256
typedef enum {
    INSERT,
    SELECT,
    IDK
} Statement;
Statement parser(const char* input) {
    if(strncmp(input, "insert", 6) == 0) {return INSERT;}
    else if (strncmp(input, "select", 6) == 0) {return SELECT;}
    else {return IDK;}
}
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
        if ((len!=0) && (input[len - 1] == '\n'))
            input[len - 1] = '\0';
        if (input[0] == '.') {
            if (strcmp(input, ".exit") == 0) {
                puts("Bye!");
                break;
            }
            else if (strcmp(input, ".help") == 0) {
                printf("Available commands: \n .exit    Exit the data base \n .help    Show this help message\n");
                continue;
            }
        }
        Statement curr = parser(input);
        if (curr == INSERT) {
            puts("Insert recogonized");
            continue;
        }
        else if (curr == SELECT) {
            puts("Select recogonized");
            continue;
        }
        printf("Unrecognized keyword at start of '%s'\n", input);
    }
    return 0;
}
