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