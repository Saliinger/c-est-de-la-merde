#include "gnl.h"

int main(int ac, char **av)
{
    int fd;
    char *line;

    if (ac < 1)
        return 1;
    fd = open(av[1], O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    printf("lol\n");
    return 0;
}
