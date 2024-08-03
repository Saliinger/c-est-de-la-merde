#include "get_next_line.h"

int main(int ac, char **av)
{
    int fd;
    char *line;
    int i = 0;

    if (ac < 1)
        return 1;
    fd = open(av[1], O_RDONLY);
    line = get_next_line(fd);
    while (i < 5)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
        i++;
    }
    return 0;
}
