/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucavall <lucavall@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:01:42 by lucavall          #+#    #+#             */
/*   Updated: 2023/11/09 17:30:38 by lucavall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_el;
	void	*bella_ste;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		bella_ste = f(lst->content);
		new_el = ft_lstnew(bella_ste);
		if (!new_el)
		{
			ft_lstclear(&new_lst, del);
			del(bella_ste);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_el);
		lst = lst->next;
	}
	return (new_lst);
}
