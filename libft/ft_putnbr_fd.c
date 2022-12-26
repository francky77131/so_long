/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:49:10 by franckgojar       #+#    #+#             */
/*   Updated: 2022/05/19 10:50:58 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	toto;

	toto = n;
	if (toto < 0)
	{
		write(fd, "-", 1);
		toto *= -1;
	}
	if (toto >= 10)
	{
		ft_putnbr_fd(toto / 10, fd);
		ft_putnbr_fd(toto % 10, fd);
	}
	if (toto < 10)
	{
		toto = toto + '0';
		write(fd, &toto, 1);
	}
}
