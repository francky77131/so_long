/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:20:56 by frgojard          #+#    #+#             */
/*   Updated: 2022/09/13 13:24:29 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_hexa(size_t nbr, char *base)
{
	int			i;

	i = 0;
	if (nbr < 16)
		i += ft_putchar(base[nbr]);
	else if (nbr >= 16)
	{
		i += ft_putnbr_hexa(nbr / 16, base);
		i += ft_putnbr_hexa(nbr % 16, base);
	}
	return (i);
}
