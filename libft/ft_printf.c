/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucavall <lucavall@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:15:46 by lucavall          #+#    #+#             */
/*   Updated: 2024/02/04 17:48:19 by lucavall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_pointers(va_list args)
{
	void	*ptr;
	int		counter;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	else
	{
		counter = 0;
		counter += write(1, "0x", 2);
		counter += ft_point((unsigned long)ptr, 16);
		return (counter);
	}
}

static int	ft_checkf(char f, va_list args)
{
	if (f == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (f == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (f == 'i' || f == 'd')
		return (ft_putnum_base((long)(va_arg(args, int)), 10));
	else if (f == 'u')
		return (ft_putnum_base((long)(va_arg(args, unsigned int)), 10));
	else if (f == 'x')
		return (ft_putnum_base((long)(va_arg(args, unsigned int)), 16));
	else if (f == 'X')
		return (ft_putnum_base_up((long)(va_arg(args, unsigned int)), 16));
	else if (f == 'p')
		return (handle_pointers(args));
	else
		return (write(1, &f, 1));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		counter;

	va_start(args, format);
	counter = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			counter += ft_checkf(*(++format), args);
		else
			counter += write(1, format, 1);
		++format;
	}
	va_end(args);
	return (counter);
}
