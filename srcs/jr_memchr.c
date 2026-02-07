/* ************************************************************************** */
/*                                              //  __________________ \\     */
/*                                             //   \##### :: #######/ //     */
/*   jr_memchr.c                               \\    \##__|::|##__##/ //      */
/*                                                ()      |++|  ______        */
/*   By: julien <julienrollan@gmx.fr>          ()     /|  |++|        \       */
/*                                                 ()/#|__|##   /      |      */
/*   Created: 2025/12/21 09:58:00 by julien         /_____|    /| |   /       */
/*   Updated: 2025/12/21 10:00:00 by julien        /_________ />++| \-\       */
/*                                                /::::::::: /<|_|  \__\      */
/* ************************************************************************** */
#include "libjr.h"

void	*jr_memchr(void *s, int c, size_t n)
{
	size_t pos;
	unsigned char *ptr;

	pos = 0;
	ptr = (unsigned char *)s;
	while (pos < n)
	{
		if (ptr[pos] == (unsigned char)c)
				return (ptr + pos);
		pos++;
	}
	return (NULL);
}
