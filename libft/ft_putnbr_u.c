/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:45:08 by frgojard          #+#    #+#             */
/*   Updated: 2022/09/13 13:24:39 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_u(unsigned int nb)
{
	long int	nbr;
	int			i;

	i = 0;
	nbr = nb;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-');
		i++;
	}
	if (nbr >= 10)
	{
		i += ft_putnbr_count(nbr / 10);
		i += ft_putnbr_count(nbr % 10);
	}
	if (nbr < 10)
	{
		nbr += '0';
		i += ft_putchar(nbr);
	}
	return (i);
}
