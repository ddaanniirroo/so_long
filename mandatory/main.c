/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprester <cprester@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:27:36 by cprester          #+#    #+#             */
/*   Updated: 2022/01/29 17:00:24 by cprester         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_all(char *argv_1, t_vars *vars)
{
	check_min(vars, 0, 0);
	check_rectangular(vars);
	check_wall(vars);
	check_char(vars);
	check_map_extension(argv_1);
}

void	win(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->win, 50, 50);
}

int	ft_render(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	ft_draw_pic(vars);
	if (vars->numb_c == 0 && vars->ok_win == 1)
		win(vars);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*line;
	t_vars	vars;

	if (argc == 2)
	{
		vars.size = 32;
		vars.fd = open(argv[1], O_RDONLY);
		if (vars.fd < 0)
			exit(EXIT_FAILURE);
		line = get_next_line(vars.fd);
		vars.map = ft_split(line, '\n', &vars);
		close(vars.fd);
		free (line);
		vars.mlx = mlx_init();
		vars.win = mlx_new_window(vars.mlx, (vars.size * vars.length),
				(vars.size * vars.width), "cprester");
		ft_assignment_pic(&vars);
		check_all(argv[1], &vars);
		mlx_hook(vars.win, 17, 0, free_all, &vars);
		mlx_hook(vars.win, 02, 0, key_hook, &vars);
		mlx_loop_hook(vars.mlx, ft_render, &vars);
		mlx_loop(vars.mlx);
	}
}
