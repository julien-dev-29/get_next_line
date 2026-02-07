/* ************************************************************************** */
/*                                              //  __________________ \\     */
/*                                             //   \##### :: #######/ //     */
/*   jr_strncat.c                              \\    \##__|::|##__##/ //      */
/*                                                ()      |++|  ______        */
/*   By: julien <julienrollan@gmx.fr>          ()     /|  |++|        \       */
/*                                                 ()/#|__|##   /      |      */
/*   Created: 2025/12/21 09:58:00 by julien         /_____|    /| |   /       */
/*   Updated: 2025/12/21 10:00:00 by julien        /_________ />++| \-\       */
/*                                                /::::::::: /<|_|  \__\      */
/* ************************************************************************** */
#include "libjr.h"

char	*jr_strncat(char *dst, const char *src, size_t ssize)
{
	size_t	slen;
	size_t	dlen;

	slen = 0;
	dlen = 0;
	while (dst[dlen] != '\0')
		dlen++;
	while (src[slen] != '\0' && slen < ssize)
	{
		dst[dlen + slen] = src[slen];
		slen++;
	}
	dst[dlen + slen] = '\0';
	return (dst);
}
