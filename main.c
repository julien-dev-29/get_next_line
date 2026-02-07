#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define PERMS 0666

int	jr_strlen(const char *str)
{
	int	n;

	if (!str)
		return (-1);
	n = 0;
	while(str[n] != '\0')
		n++;
	return (n);
}

char	*jr_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	result = malloc(sizeof(char) * (i + j + 1));
	if (!result)
		return (NULL);
	if (!s1 || !s2 || !result)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}

void	error(char *str)
{
	printf("%s", str);
}

int	contains_newline(char *s)
{
	int	i;
	int len;

	i = 0;
	len = jr_strlen(s);
	while (i < len)
		if (s[i++] == '\n')
			return (1);
	return (0);
}

char	*extract_line(char *stash)
{
	char	*res;
	size_t	n;

	res = (char *)malloc(jr_strlen(stash) + 1);
	if (!res)
		return (NULL);
	n = 0;
	while (stash[n] != '\n')
	{
		res[n] = stash[n];
		n++;
	}
	res[n] = '\0';
	return (res);
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
