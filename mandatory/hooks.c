/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprester <cprester@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:12:37 by cprester          #+#    #+#             */
/*   Updated: 2022/01/29 18:56:40 by cprester         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_key_a(t_vars *vars)
{
	if (vars->map[vars->npc_y][vars->npc_x - 1] != '1')
	{
		if (vars->map[vars->npc_y][vars->npc_x - 1] == '0')
		{
			vars->map[vars->npc_y][vars->npc_x] = '0';
			vars->map[vars->npc_y][vars->npc_x - 1] = 'P';
		}
		else if (vars->map[vars->npc_y][vars->npc_x - 1] == 'C')
		{
			vars->map[vars->npc_y][vars->npc_x] = '0';
			vars->map[vars->npc_y][vars->npc_x - 1] = 'P';
			vars->numb_c--;
		}
		else if (vars->map[vars->npc_y][vars->npc_x - 1] == 'E'
				&& vars->numb_c == 0)
			vars->ok_win = 1;
		if (vars->map[vars->npc_y][vars->npc_x - 1] != 'E')
			vars->moves++;
		vars->npc_x--;
		printf("Moves: %d\n", vars->moves);
	}
}

void	ft_key_w(t_vars *vars)
{
	if (vars->map[vars->npc_y - 1][vars->npc_x] != '1')
	{
		if (vars->map[vars->npc_y - 1][vars->npc_x] == '0')
		{
			vars->map[vars->npc_y][vars->npc_x] = '0';
			vars->map[vars->npc_y - 1][vars->npc_x] = 'P';
		}
		else if (vars->map[vars->npc_y - 1][vars->npc_x] == 'C')
		{
			vars->map[vars->npc_y][vars->npc_x] = '0';
			vars->map[vars->npc_y - 1][vars->npc_x] = 'P';
			vars->numb_c--;
		}
		else if (vars->map[vars->npc_y - 1][vars->npc_x] == 'E'
				&& vars->numb_c == 0)
			vars->ok_win = 1;
		if (vars->map[vars->npc_y - 1][vars->npc_x] != 'E')
			vars->moves++;
		vars->npc_y--;
		printf("Moves: %d\n", vars->moves);
	}
}

void	ft_key_s(t_vars *vars)
{
	if (vars->map[vars->npc_y + 1][vars->npc_x] != '1')
	{
		if (vars->map[vars->npc_y + 1][vars->npc_x] == '0')
		{
			vars->map[vars->npc_y][vars->npc_x] = '0';
			vars->map[vars->npc_y + 1][vars->npc_x] = 'P';
		}
		else if (vars->map[vars->npc_y + 1][vars->npc_x] == 'C')
		{
			vars->map[vars->npc_y][vars->npc_x] = '0';
			vars->map[vars->npc_y + 1][vars->npc_x] = 'P';
			vars->numb_c--;
		}
		else if (vars->map[vars->npc_y + 1][vars->npc_x] == 'E'
				&& vars->numb_c == 0)
			vars->ok_win = 1;
		if (vars->map[vars->npc_y + 1][vars->npc_x] != 'E')
			vars->moves++;
		vars->npc_y++;
		printf("Moves: %d\n", vars->moves);
	}
}

void	ft_key_d(t_vars *vars)
{
	if (vars->map[vars->npc_y][vars->npc_x + 1] != '1')
	{
		if (vars->map[vars->npc_y][vars->npc_x + 1] == '0')
		{
			vars->map[vars->npc_y][vars->npc_x] = '0';
			vars->map[vars->npc_y][vars->npc_x + 1] = 'P';
		}
		else if (vars->map[vars->npc_y][vars->npc_x + 1] == 'C')
		{
			vars->map[vars->npc_y][vars->npc_x] = '0';
			vars->map[vars->npc_y][vars->npc_x + 1] = 'P';
			vars->numb_c--;
		}
		else if (vars->map[vars->npc_y][vars->npc_x + 1] == 'E'
				&& vars->numb_c == 0)
			vars->ok_win = 1;
		if (vars->map[vars->npc_y][vars->npc_x + 1] != 'E')
			vars->moves++;
		vars->npc_x++;
		printf("Moves: %d\n", vars->moves);
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		free_all(vars);
	else if (keycode == A)
		ft_key_a(vars);
	else if (keycode == W)
		ft_key_w(vars);
	else if (keycode == S)
		ft_key_s(vars);
	else if (keycode == D)
		ft_key_d(vars);
	return (0);
}
