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

void	fill(t_vars *vars, int x, int y)
{
	if (vars->cpmap[y][x] == '0' || vars->cpmap[y][x] == 'P' || vars->cpmap[y][x] == 'C' || vars->cpmap[y][x] == 'E')
	{
		vars->cpmap[y][x] = 'o';
		fill(vars, x + 1, y);
		fill(vars, x - 1, y);
		fill(vars, x, y + 1);
		fill(vars, x, y - 1);
	}
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	if (len == 0)
		return (NULL);
	str = malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char **cpmap(char **map)
{
  int i;
  char **cpmap;

  i = 0;
  cpmap = malloc(sizeof(char *) * (ft_strlen(map[0]) + 1));
  while (map[i] != NULL)
  {
    cpmap[i] = ft_strdup(map[i]);     //ne pas oublier de mettre mon strdup !!!!!
	i++;
  }
  cpmap[i] = NULL;
  return (cpmap);
}

int search_path(char **map)
{
	int	y;
	int x;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != '1' && map[y][x] != 'o' )
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	flood_fill(t_vars *vars)
{
	vars->cpmap = cpmap(vars->map);
	fill(vars, vars->begin_x, vars->begin_y);
	if (search_path(vars->cpmap) == 1)
	{
		free_split(vars->cpmap);
		return (1);
	}
	free_split(vars->cpmap);
	return (0);
}

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
	if (flood_fill(vars) == 1)
	 	return (write (2, "Error : false exit path\n", 25), 1);
	return (0);
}




void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->addr + (y * vars->line_length + x * (vars->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	mlxinit(t_vars *vars, int x, int y)
{
	int color;
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, 1920, 1080, "Hello world!");
	vars->img = mlx_new_image(vars->mlx, 1920, 1080);
	vars->addr = mlx_get_data_addr(vars->img, &vars->bits_per_pixel, &vars->line_length, &vars->endian);
	while (y < 75)
	{
		x = 5;
		while (x < 75)
		{
			if (x <= 25)
				color = BLUEHEX;
			else if (x > 25 && x <= 50)
				color = WHITEHEX;
			else
				color = REDHEX;
			my_mlx_pixel_put(vars, x, y, color);
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, 0, 0);
			x++;
		}
		y++;
	}
	mlx_loop(vars->mlx);
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
	int x = 0;
	while (vars->map[x])
	{
		printf("%s\n", vars->map[x]);
		x++;
	}
	mlxinit(vars, 5, 5);
	free(vars->mapline);
	free_split(vars->map);
	free(vars);
	close(fd);
}