/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_def.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprester <cprester@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:20:20 by cprester          #+#    #+#             */
/*   Updated: 2022/01/28 21:55:28 by cprester         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->width)
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
}

int	free_all(t_vars *vars)
{
	free_map(vars);
	free(vars->img);
	exit(EXIT_SUCCESS);
}
