/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:29:39 by frgojard          #+#    #+#             */
/*   Updated: 2023/01/04 19:06:04 by frgojard         ###   ########.fr       */
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
		if (mapgnl == NULL)
			return (NULL);
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

void	print_map(t_vars *vars)
{
	int y = 0;
	int x = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			if (vars->map[y][x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->three, x * 32, y * 32);
			else if (vars->map[y][x] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->floor, x * 32, y * 32);
			else if (vars->map[y][x] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->end, x * 32, y * 32);
			else if (vars->map[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->collectible, x * 32, y * 32);
			else if (vars->map[y][x] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, vars->player, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void    img_init(t_vars *vars)
{
    int    img_width;
    int    img_height;

	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->len_x, vars->len_y, "Hello world!");
    vars->player = mlx_xpm_file_to_image
        (vars->mlx, "img/player.xpm",
            &img_width, &img_height);
    vars->three = mlx_xpm_file_to_image
        (vars->mlx, "img/three.xpm",
            &img_width, &img_height);
    vars->collectible = mlx_xpm_file_to_image
        (vars->mlx, "img/collectible.xpm",
            &img_width, &img_height);
    vars->end = mlx_xpm_file_to_image
        (vars->mlx, "img/end.xpm",
            &img_width, &img_height);
    vars->floor = mlx_xpm_file_to_image
        (vars->mlx, "img/floor.xpm",
            &img_width, &img_height);
}

int	ft_close(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->three);
	mlx_destroy_image(vars->mlx, vars->player);
	mlx_destroy_image(vars->mlx, vars->collectible);
	mlx_destroy_image(vars->mlx, vars->end);
	mlx_destroy_image(vars->mlx, vars->floor);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mapline);
	free(vars->mlx);
	free_split(vars->map);
	free(vars);
	exit(0);
}


int loop(t_vars *vars)
{
	print_map(vars);
	return (0);
}

void	move_count(void)
{
	static int	move = 0;

	ft_putstr(BLUE);
	ft_putnbr(++move);
	ft_putstr(CYAN" moves\n"END);
}

int coin_count(t_vars *vars)
{
	int i;
	int y;
	int x;

	y = 0;
	i = 0;
	while (vars->map[y])
	{
		x = 0;
		while(vars->map[y][x])
		{
			if (vars->map[y][x] == 'C')
				i++;
			x++;
		}
		y++;
	}
	return (i);
}

void ft_move(t_vars *vars, int updown, int leftright)
{
	check_player(vars);
	check_exit(vars);
	if (vars->map[vars->begin_y][vars->begin_x] == 'P' && vars->map[vars->begin_y + updown][vars->begin_x + leftright] != '1')
	{
		if (vars->begin_x == vars->exit_x && vars->begin_y == vars->exit_y)
			vars->map[vars->begin_y][vars->begin_x] = 'E';
		else
			vars->map[vars->begin_y][vars->begin_x] = '0';
		if (vars->begin_x + leftright == vars->exit_x && vars->begin_y + updown == vars->exit_y && coin_count(vars) == 0)
			ft_close(vars);
		else
		{
			vars->map[vars->begin_y + updown][vars->begin_x + leftright] = 'P';
			move_count();
		}
		return ;
	} 
}

int		key_hook(int keycode, t_vars *vars)
{
	if (keycode == 119)
		ft_move(vars, -1, 0);
	else if(keycode == 97)
		ft_move(vars, 0, -1);
	else if(keycode == 115)
		ft_move(vars, 1, 0);
	else if(keycode == 100)
		ft_move(vars, 0, 1);
	else if(keycode == 65307)
		ft_close(vars);
	print_map(vars);
	return (0);
}


int main(int ac, char **av)
{
	int	fd;
	t_vars	*vars;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (1);
	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (1);
	vars->mapline = get_map(fd);
	if (vars->mapline == NULL)
	{
		free(vars);
		close(fd);
		return (0);
	}
	close(fd);
	vars->map = ft_split(vars->mapline, '\n');
	if (vars->map == NULL)
	{
		free(vars->mapline);
		free(vars);
		return (0);
	}
	if (check_map(vars) == 1)
	{
		free(vars->mapline);
		free_split(vars->map);
		free(vars);
		return (0);	
	}
	img_init(vars);
	print_map(vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, 17, 0, ft_close, vars);
	mlx_loop(vars->mlx);
	return (0);
}