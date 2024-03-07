/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucavall <lucavall@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:38:04 by lucavall          #+#    #+#             */
/*   Updated: 2023/10/27 18:38:35 by lucavall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s_p;
	int				i;

	s_p = s;
	i = 0;
	while (n > 0)
	{
		s_p[i] = (unsigned char)c;
		i++;
		n--;
	}
	return (s);
}
