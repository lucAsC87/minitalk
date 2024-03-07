/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucavall <lucavall@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:58:33 by lucavall          #+#    #+#             */
/*   Updated: 2023/11/01 18:03:44 by lucavall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (dest);
	if (dest == src)
		return (dest);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		i = n;
		while (i > 0)
		{
			((char *)dest)[i - 1] = ((char *)src)[i - 1];
			--i;
		}
	}
	return (dest);
}
