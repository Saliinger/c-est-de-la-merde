#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

bool ft_strchr(char *s)
{
	if (!s)
		return NULL;
	int i = 0;
	while (s && s[i])
	{
		if (s[i] == '\n')
			return true;
		i++;
	}
	return false;
}

char *ft_strjoin(char *s1, char *s2)
{
	char *res;
	int i = 0;
	int j = 0;

	if (!s1 && !s2)
		return NULL;
	if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return free(s1), NULL;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	if (s1)
		free(s1);
	res[i] = '\0';
	return res;
}

char *extract_line(char *s)
{
	char *line;
	int i = 0;

	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	if (!(line = (char *)malloc(sizeof(char) * i + 2)))
		return free(s), NULL;
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return line;
}

char *clean(char *s)
{
	int i = 0;
	int j = 0;
	char *clean;

	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i]) // No newline found, free and return NULL
    {
		if (s)
			free(s);
        return NULL;
    }
	if (!(clean = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 1))))
		return free(s), NULL;
	if (s[i] == '\n')
		i++;
	while (s[i])
	{
		clean[j] = s[i];
		i++;
		j++;
	}
	clean[j] = '\0';
	if (s)
		free(s);
	return clean;
}

char *get_next_line(int fd)
{
	char *line;
	char buffer[BUFFER_SIZE + 1];
	static char *stash;
	int bytes;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	if(!stash)
	{
		if (!(stash = (char *)malloc(sizeof(char))))
			return NULL;
		stash[0] = '\0';
	}
	while (ft_strchr(stash) == false && (bytes = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	if (!stash)
		return NULL ;
	line = extract_line(stash);
	stash = clean(stash);
	if (line && line[0] == '\0')
	{
		if (line)
			free(line);
		if (stash)
			free(stash);
		return NULL;
	}
	return line;
}
