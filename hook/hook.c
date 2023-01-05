#include "../so_long.h"


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
