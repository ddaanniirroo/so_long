/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprester <cprester@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:39:58 by cprester          #+#    #+#             */
/*   Updated: 2022/01/29 18:53:19 by cprester         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_min(t_vars *vars, int i, int j)
{
	vars->numb_exit = 0;
	vars->ok_win = 0;
	vars->numb_c = 0;
	vars->numb_npc = 0;
	while (vars->map[j])
	{
		while (vars->map[j][i])
		{
			if (vars->map[j][i] == 'P')
				vars->numb_npc += 1;
			if (vars -> map[j][i] == 'C')
				vars->numb_c += 1;
			if (vars->map[j][i] == 'E')
				vars->numb_exit += 1;
			i++;
		}
		i = 0;
		j++;
	}
	if (vars->numb_npc > 1 || vars->numb_npc == 0
		|| vars->numb_c == 0 || vars->numb_exit == 0)
	{
		printf("Error\nWrong set of char\n");
		exit(EXIT_FAILURE);
	}
}

void	check_rectangular(t_vars *vars)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(vars->map[0]);
	while (vars->map[j])
	{
		if (i != ft_strlen(vars->map[j]))
		{
			printf("Error\nThe map isn't rectangular\n");
			exit(EXIT_FAILURE);
		}
		j++;
	}
}

void	check_wall(t_vars *vars)
{
	int	er;
	int	k;

	er = 0;
	k = 0;
	while (k < vars->width)
	{
		if (vars->map[k][0] != '1' || vars->map[k][vars->length - 1] != '1')
		{
			er += 1;
		}
		k++;
	}
	k = 0;
	while (k < vars->length)
	{
		if (vars->map[0][k] != '1' || vars->map[vars->width - 1][k] != '1')
			er += 1;
		k++;
	}
	if (er > 0)
	{
		printf("Error\nThe map isn't surrounded by walls\n");
		exit(EXIT_FAILURE);
	}
}

void	check_map_extension(char *argv_1)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	j = ft_strlen(argv_1) - 1;
	k = 4;
	str = malloc(sizeof(char *) * 5);
	if (str == NULL)
		return ;
	while (i < k)
	{
		str[i] = argv_1[j];
		i++;
		j--;
	}
	if (str[3] != '.' || str[2] != 'b' || str[1] != 'e'
		|| str[0] != 'r')
	{
		printf("Error\nWRONG EXT\n");
		exit(EXIT_FAILURE);
	}
	free(str);
}

void	check_char(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (vars->map[y])
	{
		while (vars->map[y][x])
		{
			if (vars->map[y][x] != '1' && vars->map[y][x] != 'P'
				&& vars->map[y][x] != '0' && vars->map[y][x] != 'A'
				&& vars->map[y][x] != 'C' && vars->map[y][x] != 'E')
			{
				printf("Error\nExtra char\n");
				exit(EXIT_FAILURE);
			}
			x++;
		}
		y++;
		x = 0;
	}
}
