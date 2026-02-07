/* ************************************************************************** */
/*                                              //  __________________ \\     */
/*                                             //   \##### :: #######/ //     */
/*   jr_strsub.c                               \\    \##__|::|##__##/ //      */
/*                                                ()      |++|  ______        */
/*   By: julien <julienrollan@gmx.fr>          ()     /|  |++|        \       */
/*                                                 ()/#|__|##   /      |      */
/*   Created: 2025/12/21 09:58:00 by julien         /_____|    /| |   /       */
/*   Updated: 2025/12/21 10:00:00 by julien        /_________ />++| \-\       */
/*                                                /::::::::: /<|_|  \__\      */
/* ************************************************************************** */
#include "libjr.h"

char	*jr_strsub(const char *s, unsigned int start, size_t n)
{
	size_t	i;
	char	*result;

	result = malloc(sizeof(char) * (n + 1));
	if (!s || !start || !n || !result)
		return (NULL);
	i = 0;
	while (i < n)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
