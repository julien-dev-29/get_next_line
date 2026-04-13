#include "get_next_line.h"

char	*extract_line(char *stash)
{
	int	i;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	return jr_substr(stash, 0, i);
}

char	*clean_stash(char *stash)
{
	char	*new_stash;
	int	i;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;
	new_stash = jr_substr(stash, i, jr_strlen(stash) - i);
	free(stash);
	return (new_stash);
}

int	get_next_line(int fd, char **line)
{
	static	char	*stash;	
	char			*buffer;
	int				bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!stash)
	{
		stash = malloc(1);
		if (!stash)
			return (-1);
		stash[0] = '\0';
	}
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	while (jr_strchr(stash, '\n') == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(stash);
			return (-1);
		}
		if (bytes_read == 0)
			break;	
		buffer[bytes_read] = '\0';
		stash = jr_strjoin(stash, buffer);
	}
	free(buffer);
	if (!stash[0])
	{
		free(stash);
		stash = NULL;
		return (0);
	}
    *line = extract_line(stash);
    stash = clean_stash(stash);
	return (1);
}
