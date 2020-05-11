#include "get_next_line_func/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    char    *line;
    int     fd1;
    int     fd2;

    fd1 = open("test.txt", O_RDONLY);
    get_next_line(fd1, &line);
    printf("LINE 1: %s\n\n", line);

    get_next_line(fd1, &line);
    printf("LINE 2: %s\n\n", line);
        
    get_next_line(fd1, &line);
    printf("LINE 3: %s\n\n", line);

    fd2 = open("test2.txt", O_RDONLY);
    get_next_line(fd2, &line);
    printf("LINE 1: %s\n\n", line);

    get_next_line(fd2, &line);
    printf("LINE 2: %s\n\n", line);
        
    get_next_line(fd2, &line);
    printf("LINE 3: %s\n\n", line);
    return (0);
}