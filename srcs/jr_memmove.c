/* ************************************************************************** */
/*                                              //  __________________ \\     */
/*                                             //   \##### :: #######/ //     */
/*   jr_memcpy.c                               \\    \##__|::|##__##/ //      */
/*                                                ()      |++|  ______        */
/*   By: julien <julienrollan@gmx.fr>          ()     /|  |++|        \       */
/*                                                 ()/#|__|##   /      |      */
/*   Created: 2025/12/21 09:58:00 by julien         /_____|    /| |   /       */
/*   Updated: 2025/12/21 10:00:00 by julien        /_________ />++| \-\       */
/*                                                /::::::::: /<|_|  \__\      */
/* ************************************************************************** */
#include "libjr.h"

void	*jr_memmove(void *dst, void *src, size_t n)
{
	size_t	pos;
	unsigned char *d;
	unsigned char *s;

	if (!dst && !src)
		return (NULL);
	pos = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d < s)
	{
		while (pos < n)
		{
			d[pos] = s[pos];
			pos++;
		}
	}
	else
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}

	}
	return (dst);
}
