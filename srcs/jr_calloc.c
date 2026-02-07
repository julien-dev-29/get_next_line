/* ************************************************************************** */
/*                                              //  __________________ \\     */
/*                                             //   \##### :: #######/ //     */
/*   jr_calloc.c                               \\    \##__|::|##__##/ //      */
/*                                                ()      |++|  ______        */
/*   By: julien <julienrollan@gmx.fr>          ()     /|  |++|        \       */
/*                                                 ()/#|__|##   /      |      */
/*   Created: 2026/01/25 09:58:00 by julien         /_____|    /| |   /       */
/*   Updated: 2026/01/25 10:00:00 by julien        /_________ />++| \-\       */
/*                                                /::::::::: /<|_|  \__\      */
/* ************************************************************************** */
#include "libjr.h"
#include <stdio.h>
#include <stdint.h>

void	*jr_calloc(size_t nmenb, size_t size)
{
	void	*ptr;
	size_t	total_size;

	if (nmenb && SIZE_MAX / nmenb < size)
		return (NULL);
	total_size = nmenb * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	jr_bzero(ptr, total_size);
	return (ptr);
}
