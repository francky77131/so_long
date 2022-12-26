/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 20:31:39 by franckgojar       #+#    #+#             */
/*   Updated: 2022/05/19 11:40:50 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long int nbr)
{
	long int	i;

	i = 0;
	if (nbr == 0)
		i++;
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int			len;
	long int	num;
	char		*tab;

	num = n;
	len = ft_len(n);
	if (n < 0)
		num *= -1;
	tab = (char *)malloc(sizeof(*tab) * (len + 1));
	if (!tab)
		return (NULL);
	tab[len] = 0;
	len--;
	if (n == 0)
		*tab = '0';
	while (num > 0)
	{
		tab[len] = num % 10 + 48;
		num /= 10;
		len--;
	}
	if (n < 0)
		tab[len] = '-';
	return (tab);
}
