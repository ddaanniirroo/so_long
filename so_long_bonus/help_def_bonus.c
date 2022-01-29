/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_def_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprester <cprester@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:20:20 by cprester          #+#    #+#             */
/*   Updated: 2022/01/29 18:26:42 by cprester         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_res;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	s_res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s_res)
		return (NULL);
	while (s1[i] != '\0')
	{
		s_res[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{
		s_res[i] = s2[k];
		i++;
		k++;
	}
	s_res[i] = '\0';
	return (s_res);
}

void	*print_moves(t_vars *vars)
{
	char	*numb;
	char	*res;

	numb = ft_itoa(vars->moves);
	res = ft_strjoin("Moves = ", numb);
	mlx_string_put(vars->mlx, vars->win, 10, (vars->width) * 32,
		0xFFCBDB, res);
	free(numb);
	free(res);
	return (NULL);
}
