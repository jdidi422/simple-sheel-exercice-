#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>  

int main(void) {
    char cmd[1024];

    while (1) {
        printf("#cisfun$ ");
        fgets(cmd, 1024, stdin);  

   
        cmd[strcspn(cmd, "\n")] = 0;

      
        if (cmd[0] == '\0') {
            continue;
        }

      
        if (fork() == 0) {
          
            char *args[] = {cmd, NULL}; 
            if (execv(cmd, args) == -1) {
                perror("Erreur");
                exit(1);
            }
        } else {
            wait(NULL);  
        }
    }

    return 0;
}
