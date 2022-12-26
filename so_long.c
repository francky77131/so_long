/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:29:39 by frgojard          #+#    #+#             */
/*   Updated: 2022/12/26 14:35:15 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*get_map
permet de lire ma map.ber
retourne ma map non split*/

char	*get_map(int fd)
{
	char	*mapgnl = NULL;
	char	*map = NULL;

	if (mapgnl == NULL)
	{
		mapgnl = get_next_line(fd);
		map = ft_strdup_gnl(mapgnl);
		free(mapgnl);
	}
	while (mapgnl != NULL)
	{
		mapgnl = get_next_line(fd);
		if (mapgnl != NULL)
			map = ft_strjoin(map, mapgnl);
		free(mapgnl);
	}
	return (map);
}

int	check_player(t_vars *vars)
{
	int	x;
	int	y;
	int player;

	y = 0;
	player = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'P')
				player++;
			x++;
		}
		y++;
	}
	if (player != 1)
		return (1);
	return (0);
}

int	check_collectible(t_vars *vars)
{
	int	x;
	int	y;
	int collectible;

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

int	check_exit(t_vars *vars)
{
	int	x;
	int	y;
	int exit;

	y = 0;
	exit = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == 'E')
				exit++;
			x++;
		}
		y++;
	}
	if (exit != 1)
		return (1);
	return (0);
}

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

int	check_shape(t_vars *vars)
{
	int	x;
	int	y;
	int	lenx;
	int	leny;

	y = 1;
	x = 0;
	leny = 0;
	lenx = 0;
	while (vars->map[leny])
		leny++;
	while (vars->map[0][lenx])
		lenx++;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
			x++;
		if (x != lenx)
			return (1);
		y++;
	}
	if (y != leny)
		return (1);
	return (0);
}

// typedef struct	s_point
// {
// 	int			x;
// 	int			y;
// }				t_point;

// void	fill(char **tab, t_point size, t_point cur, char to_fill)
// {
// 	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
// 		|| tab[cur.y][cur.x] != to_fill)
// 		return;

// 	tab[cur.y][cur.x] = 'F';
// 	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
// 	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
// 	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
// 	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
// }

// void	flood_fill(char **tab, t_point size, t_point begin)
// {
// 	fill(tab, size, begin, tab[begin.y][begin.x]);
// }

int	check_map(t_vars *vars)
{
	if (check_shape(vars) == 1)
		return (write (2, "Error : the map must be rectangular\n", 37), 1);
	if (check_wall(vars) == 1)
		return (write (2, "Error : there must be walls all around\n", 40), 1);
	if (check_player(vars) == 1)
		return (write (2, "Error : more or less than 1 player\n", 36), 1);
	if (check_collectible(vars) == 1)
		return (write (2, "Error : you need at least one collectible\n", 43), 1);
	if (check_exit(vars) == 1)
		return (write (2, "Error : more or less than 1 exit\n", 34), 1);
	// if (flood_fill(vars.) == 1)
	// 	return (write (2, "Error : false exit path\n", 25), 1);
	return (0);
}

void	init_size(t_vars *vars)
{
	int	lenx;
	int	leny;

	leny = 0;
	lenx = 0;
	while (vars->map[leny])
		leny++;
	while (vars->map[0][lenx])
		lenx++;
	vars->size_x = lenx;
	vars->size_y = leny;
}

void	vars_init(t_vars *vars)
{
	init_size(vars);
}

int main(int ac, char **av)
{
	(void)ac;
	int	fd;
	t_vars	*vars;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (1);
	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (1);
	vars->mapline = get_map(fd);
	vars->map = ft_split(vars->mapline, '\n');
	if (check_map(vars) == 1)
	{
		free(vars->mapline);
		free_split(vars->map);
		free(vars);
		close(fd);
		return (0);	
	}
	vars_init(vars);
	free(vars->mapline);
	free_split(vars->map);
	free(vars);
	close(fd);
}