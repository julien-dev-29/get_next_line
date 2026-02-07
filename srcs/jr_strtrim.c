/* ************************************************************************** */
/*                                              //  __________________ \\     */
/*                                             //   \##### :: #######/ //     */
/*   jr_strtrim.c                              \\    \##__|::|##__##/ //      */
/*                                                ()      |++|  ______        */
/*   By: julien <julienrollan@gmx.fr>          ()     /|  |++|        \       */
/*                                                 ()/#|__|##   /      |      */
/*   Created: 2025/12/21 09:58:00 by julien         /_____|    /| |   /       */
/*   Updated: 2025/12/21 10:00:00 by julien        /_________ />++| \-\       */
/*                                                /::::::::: /<|_|  \__\      */
/* ************************************************************************** */
#include "libjr.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char	*jr_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	size_t	len;
	size_t	i;
	char	*result;
	
	if (!s)
		return (NULL);
	start = 0;
	while (s[start] && is_space(s[start]))
		start++;
	if (s[start] == '\0')
	{
		result = malloc(sizeof(char) * 1);
		if (result)
			result[0] = '\0';
		return (result);
	}
	end = start;
	while (s[end])
		end++;
	end--;
	while(is_space(s[end]))
		end--;
	len = end - start + 1;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[len] = '\0';
	return (result);
}
