/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:49:09 by frgojard          #+#    #+#             */
/*   Updated: 2023/01/05 15:29:23 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**cpmap(char **map, t_vars *vars)
{
	int		i;
	char	**cpmap;

	i = 0;
	cpmap = malloc(sizeof(char *) * (vars->len_y + 1));
	if (!cpmap)
		return (NULL);
	while (map[i] != NULL)
	{
		cpmap[i] = ft_strdup(map[i]);
		if (!cpmap)
			return (NULL);
		i++;
	}
	cpmap[i] = NULL;
	return (cpmap);
}

int	search_path(char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != 'o' && map[y][x] != '0' )
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	fill(t_vars *vars, int x, int y)
{
	if (vars->cpmap[y][x] == '0' || vars->cpmap[y][x] == 'P'
		|| vars->cpmap[y][x] == 'C' || vars->cpmap[y][x] == 'E')
	{
		vars->cpmap[y][x] = 'o';
		fill(vars, x + 1, y);
		fill(vars, x - 1, y);
		fill(vars, x, y + 1);
		fill(vars, x, y - 1);
	}
}

int	flood_fill(t_vars *vars)
{
	vars->cpmap = cpmap(vars->map, vars);
	fill(vars, vars->begin_x, vars->begin_y);
	if (search_path(vars->cpmap) == 1)
	{
		free_split(vars->cpmap);
		return (1);
	}
	free_split(vars->cpmap);
	return (0);
}
