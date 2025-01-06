#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <sys/wait.h>

void check_command(char *command) {
    if (access(command, F_OK) == 0) { 
        printf("%s: Found\n", command);
    } else {
        printf("%s: NOT FOUND\n", command);
    }
}

int main() {
    char *buffer = NULL;
    size_t buffer_size = 0; 
    ssize_t chars;
    char *token;

    while (1) {
        write(1, "$ ", 2);
        chars = getline(&buffer, &buffer_size, stdin);
        if (chars == -1) {
            perror("getline");
            break;
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        token = strtok(buffer, " \t\n");
        if (token != NULL && strcmp(token, "which") == 0) {
            token = strtok(NULL, " \t\n");
            if (token != NULL) {
                check_command(token);
            } else {
                printf("No command specified after 'which'.\n");
            }
        } else {
            printf("Command doesn't exist\n");
        }
    }

    free(buffer);
    return 0;
}
