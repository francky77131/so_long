#include "../so_long.h"

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