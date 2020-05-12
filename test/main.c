#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    char *line;
    int count = 0;
    int fd1;

    fd1 = open("test1.txt", O_RDONLY);
    while (get_next_line(fd1, &line))
    {
        count++;
        printf("LINE %d : %s\n", count, line);
    }
    printf("LINE %d : %s\n", ++count, line);
    get_next_line(fd1, &line);
    printf("LINE %d : %s\n", ++count, line);
    return (0);
}