/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucavall <lucavall@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:37:06 by lucavall          #+#    #+#             */
/*   Updated: 2023/11/06 17:11:44 by lucavall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		num;
	int		minus;

	i = 0;
	num = 0;
	minus = 1;
	while ((nptr[i] == 32) || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i] == 45)
			minus *= -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		num *= 10;
		num += nptr[i] - 48;
		i++;
	}
	return (num * minus);
}
