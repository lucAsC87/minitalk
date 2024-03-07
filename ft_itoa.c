/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucavall <lucavall@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 17:14:34 by lucavall          #+#    #+#             */
/*   Updated: 2023/11/09 15:25:37 by lucavall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	num_len(int num)
{
	unsigned int	length;

	length = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		length += 1;
	while (num != 0)
	{
		num /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	unsigned int	length;
	char			*str;
	unsigned int	num;

	length = num_len(n);
	str = malloc(sizeof(char) * length + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		num = -n;
	}
	else
		num = n;
	if (num == 0)
		str[0] = 48;
	str[length] = '\0';
	while (num != 0)
	{
		str[length - 1] = (num % 10) + 48;
		num /= 10;
		length--;
	}
	return (str);
}
