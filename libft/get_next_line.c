/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:52:02 by frgojard          #+#    #+#             */
/*   Updated: 2022/09/13 14:25:59 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_start(char *stash, int c)
{
	int	i;

	i = 0;
	while (stash[i])
	{
		i++;
		if (stash[i] == c)
			return (i + 1);
	}
	return (0);
}

int	ft_end(char *stash)
{
	int	i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	return (i + 1);
}

char	*ft_process(char *buf, int readsize, char *line, int fd)
{
	while (ft_strchr(buf, '\n') == NULL && readsize > 0)
	{
		readsize = read(fd, buf, BUFFER_SIZE);
		if (readsize <= 0 && buf[0] == 0)
			return (NULL);
		buf[readsize] = 0;
		if (line == NULL)
			line = ft_strdup_gnl(buf);
		else
			line = ft_strjoin_gnl(line, buf);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[1024][BUFFER_SIZE + 1];
	char		*line;
	int			readsize;

	readsize = 1;
	line = NULL;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE == 0)
		return (NULL);
	if (buf[fd][0] != '\0')
	{
		line = ft_strdup_gnl(buf[fd]);
		if (!line)
			return (NULL);
	}
	line = ft_process(buf[fd], readsize, line, fd);
	if (!line)
		return (NULL);
	bzero(buf[fd], BUFFER_SIZE);
	ft_stock(line, buf[fd]);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*str = NULL;
	int		i;

	i = 0;
	fd = open("test", O_RDONLY);
	if (fd == -1)
		return (1);
	while (i++ < 10)
	{
		str = get_next_line(fd);
		printf("ligne %d: %s", i, str);
		free(str);
	}	
	close(fd);
	return (0);
}