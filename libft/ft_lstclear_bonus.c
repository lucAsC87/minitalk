/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucavall <lucavall@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:23:15 by lucavall          #+#    #+#             */
/*   Updated: 2023/11/07 16:38:57 by lucavall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*copy;

	if (*lst)
	{
		while (*lst)
		{
			copy = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = copy;
		}
	}
	*lst = NULL;
}
