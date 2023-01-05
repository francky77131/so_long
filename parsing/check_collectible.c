/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collectible.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:52:40 by frgojard          #+#    #+#             */
/*   Updated: 2023/01/05 14:51:33 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_collectible(t_vars *vars)
{
	int	x;
	int	y;
	int	collectible;

	y = 0;
	collectible = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'C')
				collectible++;
			x++;
		}
		y++;
	}
	if (collectible == 0)
		return (1);
	return (0);
}
