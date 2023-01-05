/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:52:43 by frgojard          #+#    #+#             */
/*   Updated: 2023/01/05 14:46:46 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_player(t_vars *vars)
{
	int	x;
	int	y;
	int	player;

	y = 0;
	player = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'P')
			{
				vars->begin_y = y;
				vars->begin_x = x;
				player++;
			}
			x++;
		}
		y++;
	}
	if (player != 1)
		return (1);
	return (0);
}
