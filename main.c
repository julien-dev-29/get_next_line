#include "get_next_line.h"


int main(void) 
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY, 0);
	if (fd < 0)
	{
		printf("Failed to open file");
		return (1);
	}
	while (get_next_line(fd, &line) > 0 )
	{
		write(1, line, jr_strlen(line));
		//write(1, &"\n", 1);
		free(line);
	}
	close(fd);
    return (0);
}
