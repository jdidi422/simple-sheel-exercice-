#include <stdio.h>
#include <stdlib.h>

int main() {
    char *line = NULL; 
    size_t bufsize = 0; 
    
    printf("$ ");  
    
  
    if (getline(&line, &bufsize, stdin) == -1) {
        if (feof(stdin)) {
            printf("\nEnd of file detected. Exiting...\n");
            exit(0); 
        }
        perror("Error with getline");
        exit(1);
    }

  
    printf("%s", line);
    
    free(line); 
    return 0;
}

