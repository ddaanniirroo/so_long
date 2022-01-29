/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprester <cprester@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:27:59 by cprester          #+#    #+#             */
/*   Updated: 2022/01/29 18:21:17 by cprester         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 100000
# define WALL 		"pic/wall.xpm"
# define FREE 		"pic/free.xpm"
# define COLLECT 	"pic/collect.xpm"
# define EXIT 		"pic/exit.xpm"
# define NPC		"pic/npc.xpm"
# define WIN        "pic/win.xpm"
# define ESC 53
# define W 13
# define S 1
# define A 0
# define D 2

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_data{
	void	*wall;
	void	*free;
	void	*collect;
	void	*exit;
	void	*npc;
	void	*win;
}	t_data;

typedef struct s_vars{
	void	*mlx;
	void	*win;
	char	**map;
	int		fd;
	int		width;
	int		length;
	int		size;
	int		npc_x;
	int		npc_y;
	int		exit_x;
	int		exit_y;
	int		numb_c;
	int		numb_npc;
	int		numb_exit;
	int		moves;
	int		ok_win;
	int		i_for_ber;
	char	*char_ber;
	int		d_ber;
	t_data	*img;
}	t_vars;

char		*get_next_line(int fd);
void		ft_read(int fd, int *ret, char *buf, int x);
int			ft_strlen(const char *s);
char		*ft_substr(char *s, int start, size_t len);
int			ft_count(char const *s, char c);
int			ft_len(char *strr, char c);
char		**ft_split(char const *s, char c, t_vars *vars);
char		**ft_free(char **v, int h);
char		**add_words_to_str(char const *s, char c, char **str, t_vars *vars);
void		ft_assignment_pic(t_vars *vars);
void		ft_put_img(t_vars *vars, int i, int j);
void		ft_draw_pic(t_vars *vars);
int			key_hook(int keycode, t_vars *vars);
void		ft_key_s(t_vars *vars);
void		ft_key_d(t_vars *vars);
void		ft_key_w(t_vars *vars);
void		ft_key_a(t_vars *vars);
int			free_all(t_vars *vars);
int			ft_render(t_vars *vars);
void		ft_help(t_vars *vars);
void		check_min(t_vars *vars, int i, int j);
void		win(t_vars *vars);
void		check_rectangular(t_vars *vars);
void		free_map(t_vars *vars);
void		check_all(char *argv_1, t_vars *vars);
void		check_wall(t_vars *vars);
void		check_map_extension(char *argv_1);
void		check_char(t_vars *vars);

#endif