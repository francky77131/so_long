
#include "../so_long.h"

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
