/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:54:47 by frgojard          #+#    #+#             */
/*   Updated: 2023/01/05 14:47:27 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_exit(t_vars *vars)
{
	int	x;
	int	y;
	int	exit;

	y = 0;
	exit = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'E')
			{
				vars->exit_y = y;
				vars->exit_x = x;
				exit++;
			}
			x++;
		}
		y++;
	}
	if (exit != 1)
		return (1);
	return (0);
}
