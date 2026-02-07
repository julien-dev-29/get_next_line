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

char	*jr_strjoin(const char *s1, const char *s2)
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

int	contains_newline(char *s)
{
	int	i;
	int len;

	i = 0;
	len = jr_strlen(s);
	if (len < 0)
		return (0);
	while (i < len)
		if (s[i++] == '\n')
			return (1);
	return (0);
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

char	*remove_line(char *stash)
{
	char	*res;
	size_t	i;
	size_t	j;
	int		len;

	res = (char *)malloc(jr_strlen(stash) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	i++;
	j = 0;
	len = jr_strlen(stash); 
	if (len < 0)
		return (NULL);
	while (i < len)
		res[j++] = stash[i++];
	res[j] = '\0';
	return (res);
}

int	get_next_line(const int fd, char **line)
{
	static	char	*stash = NULL;
	char			buf[BUFSIZ + 1];
	size_t			r;

	while (!contains_newline(stash))
	{
		r = read(fd, buf, BUFSIZ);
		if (r <= 0)
			break;
		buf[r] = '\0';
		free(stash);
		stash = jr_strjoin(stash, buf);
	}
	if (!stash || stash[0] == '\0')
        return 0;
	*line = extract_line(stash);
	free(stash);
	stash = remove_line(stash);
	return (1);
}

int main(void) 
{
	int		fd = open("test.txt", O_RDONLY, 0);
	char	*line;
	if (get_next_line(fd, &line) == 1)
	{
		write(1, "yolo", 4);
		write(1, line, jr_strlen(line));
		write(1, "\n", 1);
		free(line);
	}
	close(fd);
    return (0);
}
