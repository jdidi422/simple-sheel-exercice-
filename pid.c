#include <stdio.h>
#include <unistd.h>

/**
 * main - prints the process ID and parent process ID
 *
 * Return: Always 0 
 */
int main(void)
{
    pid_t  pid, ppid;

    pid = getpid();
    ppid = getppid();

    printf("pid = %d\nparent id = %d\n", pid, ppid);

    return (0);
}
