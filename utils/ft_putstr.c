/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:49:45 by frgojard          #+#    #+#             */
/*   Updated: 2023/01/04 13:09:15 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_putstr(const char *str)
{
	int	i;

	i = -1;
	if (!str)
		str = "(null)";
	while (str[++i])
		ft_putchar(str[i]);
	return (i);
}
