#include <stdio.h>
#include <string.h>

extern char **environ;

char *_getenv(const char *name) {
    char **env = environ;
    size_t name_len = strlen(name);

    while (*env) {
        if (strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=') {
            return *env + name_len + 1;
        }
        env++;
    }
    return NULL;
}

int main() {
    const char *var_name = "PATH";
    char *value = _getenv(var_name);
    if (value != NULL) {
        printf("Value of %s: %s\n", var_name, value);
    } else {
        printf("%s not found in environment variables.\n", var_name);
    }
    return 0;
}
