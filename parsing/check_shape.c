/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:52:46 by frgojard          #+#    #+#             */
/*   Updated: 2023/01/05 15:10:23 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_shape(t_vars *vars)
{
	int	x;
	int	y;
	int	lenx;
	int	leny;

	y = 0;
	leny = 0;
	lenx = 0;
	while (vars->map[leny])
		leny++;
	vars->len_y = leny * 32;
	while (vars->map[0][lenx])
		lenx++;
	vars->len_x = lenx * 32;
	while (vars->map[++y])
	{
		x = 0;
		while (vars->map[y][x])
			x++;
		if (x != lenx)
			return (1);
	}
	if (y != leny)
		return (1);
	return (0);
}
