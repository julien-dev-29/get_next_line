/* ************************************************************************** */
/*                                              //  __________________ \\     */
/*                                             //   \##### :: #######/ //     */
/*   jr_memccpy.c                              \\    \##__|::|##__##/ //      */
/*                                                ()      |++|  ______        */
/*   By: julien <julienrollan@gmx.fr>          ()     /|  |++|        \       */
/*                                                 ()/#|__|##   /      |      */
/*   Created: 2025/12/21 09:58:00 by julien         /_____|    /| |   /       */
/*   Updated: 2025/12/21 10:00:00 by julien        /_________ />++| \-\       */
/*                                                /::::::::: /<|_|  \__\      */
/* ************************************************************************** */
#include "libjr.h"

void	*jr_memccpy(void *dst, void *src, int c, size_t n)
{
	size_t			pos;
	unsigned char	*d;
	unsigned char	*s;

	if (!dst || !src)
		return (0);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	pos = 0;
	while (pos < n)
	{
		d[pos] = s[pos];
		if (s[pos] == (unsigned char)c)
			return (d + pos + 1);
		pos++;
	}
	return (NULL);
}
