/* ************************************************************************** */
/*                                              //  __________________ \\     */
/*                                             //   \##### :: #######/ //     */
/*   jr_strchr.c                               \\    \##__|::|##__##/ //      */
/*                                                ()      |++|  ______        */
/*   By: julien <julienrollan@gmx.fr>          ()     /|  |++|        \       */
/*                                                 ()/#|__|##   /      |      */
/*   Created: 2025/12/21 09:58:00 by julien         /_____|    /| |   /       */
/*   Updated: 2025/12/21 10:00:00 by julien        /_________ />++| \-\       */
/*                                                /::::::::: /<|_|  \__\      */
/* ************************************************************************** */
#include "libjr.h"

char	*jr_strchr(const char *str, int c)
{
	size_t len;

	len = 0;
	while (str[len] != '\0')
	{
		if (str[len] == (unsigned char)c)
			return (char *(str + len));
		len++;
	}
	if (str[len] == (unsigned char)c)
		return (char *(str + len));
	return (NULL);
}
