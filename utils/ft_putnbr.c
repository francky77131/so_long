/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:46:54 by frgojard          #+#    #+#             */
/*   Updated: 2023/01/04 13:09:19 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putnbr(int n)
{
	long int	toto;

	toto = n;
	if (toto < 0)
	{
		write(1, "-", 1);
		toto *= -1;
	}
	if (toto >= 10)
	{
		ft_putnbr(toto / 10);
		ft_putnbr(toto % 10);
	}
	if (toto < 10)
	{
		toto = toto + '0';
		write(1, &toto, 1);
	}
}