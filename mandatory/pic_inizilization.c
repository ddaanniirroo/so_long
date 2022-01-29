/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pic_inizilization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprester <cprester@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 20:51:09 by cprester          #+#    #+#             */
/*   Updated: 2022/01/29 18:48:00 by cprester         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_assignment_pic(t_vars *vars)
{
	int	width;
	int	height;

	vars->moves = 0;
	vars->img = malloc(sizeof(t_data));
	vars->img->wall = mlx_xpm_file_to_image(vars->mlx, WALL, &width, &height);
	vars->img->free = mlx_xpm_file_to_image(vars->mlx, FREE, &width, &height);
	vars->img->npc = mlx_xpm_file_to_image(vars->mlx, NPC, &width, &height);
	vars->img->collect = mlx_xpm_file_to_image(vars->mlx,
			COLLECT, &width, &height);
	vars->img->exit = mlx_xpm_file_to_image(vars->mlx, EXIT, &width, &height);
	vars->img->win = mlx_xpm_file_to_image(vars->mlx, WIN, &width, &height);
}

void	ft_put_img(t_vars *vars, int i, int j)
{
	if (vars->map[i][j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->wall,
			j * vars->size, i * vars->size);
	else if (vars->map[i][j] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->free,
			j * vars->size, i * vars->size);
	else if (vars->map[i][j] == 'P')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->npc,
			j * vars->size, i * vars->size);
		vars->npc_x = j;
		vars->npc_y = i;
	}
	else if (vars->map[i][j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->collect,
			j * vars->size, i * vars->size);
	else if (vars->map[i][j] == 'E')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->exit,
			j * vars->size, i * vars->size);
		vars->exit_x = j;
		vars->exit_y = i;
	}
}

void	ft_draw_pic(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = 0;
		while (vars->map[i][j])
		{
			ft_put_img(vars, i, j);
			j++;
		}
		i++;
	}
}
