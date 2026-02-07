/* ************************************************************************** */
/*                                              //  __________________ \\     */
/*                                             //   \##### :: #######/ //     */
/*   jr_memcmp.c                               \\    \##__|::|##__##/ //      */
/*                                                ()      |++|  ______        */
/*   By: julien <julienrollan@gmx.fr>          ()     /|  |++|        \       */
/*                                                 ()/#|__|##   /      |      */
/*   Created: 2025/12/21 09:58:00 by julien         /_____|    /| |   /       */
/*   Updated: 2025/12/21 10:00:00 by julien        /_________ />++| \-\       */
/*                                                /::::::::: /<|_|  \__\      */
/* ************************************************************************** */
#include "libjr.h"

int	jr_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			pos;
	unsigned char	*p1;
	unsigned char	*p2;

	pos = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (pos < n)
	{
		if (p1[pos] != p2[pos])
			return (p1[pos] - p2[pos]);
		pos++;
	}
	return (0);
}
