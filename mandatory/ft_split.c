/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprester <cprester@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 00:17:15 by cprester          #+#    #+#             */
/*   Updated: 2022/01/29 17:28:21 by cprester         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count(char const *s, char c)
{
	char	*str;
	int		count;
	int		i;

	count = 0;
	i = 0;
	str = (char *) s;
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			count ++;
		i++;
	}
	return (count);
}

int	ft_len(char *strr, char c)
{
	int	i;

	i = 0;
	while (strr[i] != c && strr[i] != '\0')
		i++;
	return (i);
}

char	**ft_split(char const *s, char c, t_vars *vars)
{
	char	**str;

	if (s == NULL)
		return (NULL);
	vars->width = ft_count(s, c);
	str = (char **)malloc(sizeof(char *) * (vars->width + 1));
	if (str == NULL)
		return (NULL);
	str[vars->width] = NULL;
	str = add_words_to_str(s, c, str, vars);
	return (str);
}

char	**ft_free(char **v, int h)
{
	while (h > 0)
	{
		h--;
		free(v[h]);
	}
	free (v);
	return (NULL);
}

char	**add_words_to_str(char const *s, char c, char **str, t_vars *vars)
{
	int		i;
	int		k;
	int		j;

	k = 0;
	i = 0;
	while (i < vars->width)
	{
		while (s[k] == c && s[k] != '\0')
			k++;
		vars->length = ft_len((char *)s + k, c);
		str[i] = (char *) malloc(sizeof(char) * (vars->length + 1));
		if (str[i] == NULL)
			return (ft_free(str, i));
		str[i][vars->length] = '\0';
		j = 0;
		while (s[k] != '\0' && s[k] != c)
			str[i][j++] = s[k++];
		i++;
	}
	return (str);
}
