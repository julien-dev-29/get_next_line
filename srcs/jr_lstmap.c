/* ************************************************************************** */
/*                                              //  __________________ \\     */
/*                                             //   \##### :: #######/ //     */
/*   jr_lstmap.c                               \\    \##__|::|##__##/ //      */
/*                                                ()      |++|  ______        */
/*   By: julien <julienrollan@gmx.fr>          ()     /|  |++|        \       */
/*                                                 ()/#|__|##   /      |      */
/*   Created: 2026/01/05 16:38:00 by julien         /_____|    /| |   /       */
/*   Updated: 2026/01/05 00:00:00 by julien        /_________ />++| \-\       */
/*                                                /::::::::: /<|_|  \__\      */
/* ************************************************************************** */
#include "libjr.h"

t_list jr_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*new_elem;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	new_elem = f(lst);
	if (!new_elem)
		return (NULL);
	new_lst = jr_lstnew(new_elem->content);
	if (!new_lst)
		return (NULL);
	tmp = new_lst;
	lst = lst->next;
	while (lst)
	{
		new_elem = f(lst);
		if (!new_elem)
			return (NULL);
		tmp->next = jr_lstnew(new_elem->content);
		if (!tmp->next)
			return (NULL);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (new_lst);
}
