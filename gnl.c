/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:37:07 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/02 16:54:42 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

bool is_line(char *s)
{
    int i = 0;
    while (s[i])
    {
        if (s[i] == '\n')
            return true;
        i++;
    }
    return false;
}

char *ft_strjoin(char *s1, char *s2)
{
    char *dest;
    int i = 0;
    int j = 0;

    dest = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char ));
    if (!dest)
        return (free(s1), NULL);
    while (s1[i])
    {
        dest[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        dest[i] = s1[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}

char *extract(char *s)
{
    int i = 0;
    int j = 0;
    char *line;

    while (s[i] && s[i] != '\n')
        i++;
    i++;
    line = (char *)malloc(sizeof(char) * i + 2);
    if (!line)
        return free(s), NULL;
    while (s[j] && s[j] != '\n')
    {
        line[j] = s[j];
        j++;
    }
    if (s[j] == '\n')
    {
        line[j] = '\n';
        j++;
    }
    line[j] = '\0';
    return line;
}

char *clean(char *s)
{
    char *clean;
    int i = 0;
    int j = 0;

    while (s[i] && s[i] != '\n')
        i++;
    if (s[i] == '\n')
        i++;
    clean = (char *)malloc((ft_strlen(s) - i + 1) * sizeof(char ));
    if (!clean)
        return free(s), NULL;
    while (s[i])
    {
        clean[j] = s[i];
        j++;
        i++;
    }
    clean[j] = '\0';
    return clean;
}

char *get_next_line(int fd)
{
    char *line;
    char buffer[BS];
    static char *stash;
    int bytes = 0;

    if (!stash)
    {
        stash = (char *)malloc(sizeof (char));
        if (!stash)
            return NULL;
        stash[0] = '\0';
    }
    bytes = read(fd, buffer, BS);
    if (bytes == -1)
        return free(stash), NULL;
    if (bytes < BS && ft_strlen(stash) == 0)
        return free(stash), NULL;
    buffer[bytes] = '\0';
    while (is_line(stash) == false)
    {
        bytes = read(fd, buffer, BS);
        if (bytes == -1)
            return free(stash), NULL;
        buffer[bytes] = '\0';
        stash = ft_strjoin(stash, buffer);
        if (bytes < BS)
            break ;
    }
    line = extract(stash);
    stash = clean(stash);
    printf(("%s"),stash);
    return line;
}