/* ************************************************************************** */
/*                                              //  __________________ \\     */
/*                                             //   \##### :: #######/ //     */
/*   jr_strcpy.c                               \\    \##__|::|##__##/ //      */
/*                                                ()      |++|  ______        */
/*   By: julien <julienrollan@gmx.fr>          ()     /|  |++|        \       */
/*                                                 ()/#|__|##   /      |      */
/*   Created: 2025/12/21 09:58:00 by julien         /_____|    /| |   /       */
/*   Updated: 2025/12/21 10:00:00 by julien        /_________ />++| \-\       */
/*                                                /::::::::: /<|_|  \__\      */
/* ************************************************************************** */
#include "libjr.h"

char	*jr_strncpy(char *dst, const char *src, size_t dsize)
{
	size_t	dlen;

	dlen = 0;
	while (dlen < dsize && src[dlen] != '\0')
	{
		dst[len] = src[len];
		dlen++;
	}
	while (dlen < dsize)
	{
		dest[dlen] = '\0';
		dlen++;
	}
	return (dst);
}
