/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprester <cprester@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:28:23 by cprester          #+#    #+#             */
/*   Updated: 2022/01/27 22:33:41 by cprester         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_substr(char *s, int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	j;

	i = start;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (len > (size_t) ft_strlen(s + start))
		len = (size_t) ft_strlen(s + start);
	str = (char *) malloc (sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0' && start < ft_strlen(s) && j < len)
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_read(int fd, int *ret, char *buf, int x)
{
	*ret = read(fd, buf, x);
	buf[*ret] = '\0';
}

char	*get_next_line(int fd)
{
	static char	*rem[1024];
	int			ret;
	char		buf[BUFFER_SIZE + 1];
	int			check;

	check = -1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (rem[fd] == NULL)
	{
		ft_read(fd, &ret, buf, BUFFER_SIZE);
		rem[fd] = ft_substr(buf, 0, ft_strlen(buf));
	}
	return (rem[fd]);
}
