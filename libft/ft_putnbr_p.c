/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:03:19 by frgojard          #+#    #+#             */
/*   Updated: 2022/09/13 13:24:34 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_p(va_list args, char *base)
{
	int				i;
	unsigned long	p;

	i = 0;
	p = va_arg(args, unsigned long);
	if ((void *)p == NULL)
		i += ft_putstr("(nil)");
	else
	{
		i += ft_putstr("0x");
		i += ft_putnbr_hexa(p, base);
	}
	return (i);
}
