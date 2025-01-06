#include <stdio.h>

/**
 * main - prints all command-line arguments
 * @ac: argument count 
 * @av: argument vector 
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
(void)ac;

    int i=0;

    while (av[i])
    {
        printf("%s\n", av[i]);
        i++;
    }

    return 0;
}
