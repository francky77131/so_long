/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:38:10 by frgojard          #+#    #+#             */
/*   Updated: 2022/09/13 13:23:00 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_arg(char c, va_list args, int size)
{
	if (c == 'c')
		size += ft_putchar(va_arg(args, int));
	if (c == 's')
		size += ft_putstr(va_arg(args, char *));
	if (c == 'd' || c == 'i')
		size += ft_putnbr_count(va_arg(args, int));
	if (c == 'u')
		size += ft_putnbr_u(va_arg(args, int));
	if (c == '%')
		size += ft_putchar('%');
	if (c == 'x')
		size += ft_putnbr_hexa(va_arg(args, unsigned int), "0123456789abcdef");
	if (c == 'X')
		size += ft_putnbr_hexa(va_arg(args, unsigned int), "0123456789ABCDEF");
	if (c == 'p')
		size += ft_putnbr_p(args, "0123456789abcdef");
	return (size);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		size;

	i = 0;
	size = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] != '%')
			size += ft_putchar(s[i]);
		else
		{
			size += ft_check_arg(s[i + 1], args, 0);
			i++;
		}
		i++;
	}
	va_end(args);
	return (size);
}
