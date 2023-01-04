/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:52:51 by frgojard          #+#    #+#             */
/*   Updated: 2023/01/04 14:55:29 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


int	check_wall(t_vars *vars)
{
	int	x;
	int	y;
	int lenx;

	lenx = -1;
	y = 0;
	x = 0;
	while (vars->map[0][++lenx])
	{
		if (vars->map[0][lenx] != '1')
			return (1);
	}
	lenx--;
	while (vars->map[++y])
	{
		if (vars->map[y][x] != '1' || vars->map[y][lenx] != '1')
			return (1);
	}
	lenx = -1;
	while (vars->map[y - 1][++lenx])
	{
		if (vars->map[y - 1][lenx] != '1')
			return (1);
	}
	return (0);
}