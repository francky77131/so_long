/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frgojard <frgojard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:00:00 by frgojard          #+#    #+#             */
/*   Updated: 2023/01/05 15:15:27 by frgojard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "./mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <stddef.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_vars
{
	char	**map;
	char	**cpmap;
	char	*addr;
	char	*mapline;
	void	*mlx;
	void	*win;
	void	*img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		exit_y;
	int		exit_x;
	int		begin_x;
	int		begin_y;
	int		len_x;
	int		len_y;
	void	*player;
	void	*three;
	void	*collectible;
	void	*floor;
	void	*end;
}	t_vars;

/*GNL*/
size_t	ft_strlen(const char *s);
int		ft_start(char *stash, int c);
int		ft_end(char *stash);
char	*ft_process(char *buf, int readsize, char *line, int fd);
char	*get_next_line(int fd);
char	*ft_strdup_gnl(char *s);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_stock(char *line, char *buf);
char	*ft_strchr(const char *s, int c);

/*Split*/
size_t	count_words(const char *s, char c);
size_t	sizeof_word(const char *s, char c);
char	**free_tab(char **tab, size_t size);
char	**ft_split(const char *s, char c);
void	free_split(char **args);

/*utils*/
char	*ft_strjoin(char *s1, char *s2);
void	ft_putnbr(int n);
char	*ft_strdup(const char *s);
int		ft_putchar(char c);
int		ft_putstr(const char *str);

/*parsing*/
int		check_collectible(t_vars *vars);
int		check_exit(t_vars *vars);
int		check_player(t_vars *vars);
int		check_shape(t_vars *vars);
int		check_wall(t_vars *vars);
void	fill(t_vars *vars, int x, int y);
int		flood_fill(t_vars *vars);
char	*get_map(int fd);
int		check_map(t_vars *vars);
char	**cpmap(char **map, t_vars *vars);
int		search_path(char **map);

/*hook*/
int		key_hook(int keycode, t_vars *vars);
void	ft_move(t_vars *vars, int updown, int leftright);
void	move_count(void);
int		coin_count(t_vars *vars);
void	print_map(t_vars *vars, int x, int y);
int		ft_close(t_vars *vars);

# define RED     "\x1b[31;1m"
# define GREEN   "\x1b[32;1m"
# define YELLOW  "\x1b[33;1m"
# define BLUE    "\x1b[34;1m"
# define MAGENTA "\x1b[35;1m"
# define CYAN    "\x1b[36;1m"
# define END    "\x1b[0m"

#endif