#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define PERMS 0666

int	jr_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*jr_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

char	*jr_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	j = 0;
	res = malloc(jr_strlen(s1) + jr_strlen(s2)  + 1);
	if (!res)
		return (NULL);
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

char	*extract_line(char *stash)
{
	int		i;
	char	*line;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*clean_stash(char *stash)
{
	size_t	i;
	size_t	j;
	char	*new_stash;
	
	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;
	new_stash = (char *)malloc(jr_strlen(stash) - i + 1);
	if (!new_stash)
		return (NULL);
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

int	get_next_line(const int fd, char **line)
{
	static	char	*stash;
	char			buffer[BUFSIZ + 1];
	size_t			bytes;

	if (fd < 0 || !line || BUFSIZ <=0)
		return (-1);
	bytes = 1;
	while(!jr_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFSIZ);
		if (bytes < 0)
			return (-1);
		buffer[bytes] = '\0';
		stash = jr_strjoin(stash, buffer);
	}
	if (bytes == 0 && (!stash || !stash[0]))
			return (0);
	*line = extract_line(stash);
	stash = clean_stash(stash);
	return (1);
}

int main(void) 
{
	int		fd = open("test.txt", O_RDONLY, 0);
	char	*line;
	while (get_next_line(fd, &line) > 0 )
	{
		write(1, line, jr_strlen(line));
		write(1, "\n", 1);
		free(line);
	}
	close(fd);
    return (0);
}
