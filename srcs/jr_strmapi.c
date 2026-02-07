/* ************************************************************************** */
/*                                              //  __________________ \\     */
/*                                             //   \##### :: #######/ //     */
/*   jr_strmap.c                               \\    \##__|::|##__##/ //      */
/*                                                ()      |++|  ______        */
/*   By: julien <julienrollan@gmx.fr>          ()     /|  |++|        \       */
/*                                                 ()/#|__|##   /      |      */
/*   Created: 2025/12/28 16:56:00 by julien         /_____|    /| |   /       */
/*   Updated: 2025/12/28 10:00:00 by julien        /_________ />++| \-\       */
/*                                                /::::::::: /<|_|  \__\      */
/* ************************************************************************** */
#include "libjr.h"

char	*jr_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*result;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	result = malloc(sizeof(char) * (i + 1));
	if (!result || !s || !f)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
