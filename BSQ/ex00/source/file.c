/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:20:28 by alde-fre          #+#    #+#             */
/*   Updated: 2022/02/22 01:20:29 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "file.h"

int	ft_atoin(char *str, int n)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (i < n)
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

unsigned int	ft_strlen_c(char *str, char c)
{
	unsigned int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*ft_check_line(char *str, char *set, int size_x, int size_y)
{
	int	i;
	int	j;

	j = -1;
	while (set[++j] != '\n')
		if (set[j] < ' ' || set[j] > '~')
			return (0);
	j = 0;
	while (*str)
	{
		i = -1;
		while (str[++i] != '\n' && str[i])
			if (str[i] != set[0] && str[i] != set[1])
				return (0);
		if (i != size_x)
			return (0);
		if (str[i] == 0)
			break ;
		str = str + size_x + 1;
		j++;
	}
	if (j != size_y)
		return (0);
	return (str);
}

t_map	*ft_check_file(char *str)
{
	int		i;
	int		j;
	int		size_x;
	int		size_y;
	char	*set;

	i = ft_strlen_c(str, '\n');
	j = 0;
	while (str[j] >= '0' && str[j] <= '9' && j < i - 3)
		j++;
	if (i <= 3 || j < i - 3)
		return (0);
	set = str + i - 3;
	if (set[0] == set[1] || set[0] == set[2] || set[1] == set[2])
		return (0);
	size_x = ft_strlen_c(str + i + 1, '\n');
	if (size_x == 0)
		return (0);
	size_y = ft_atoin(str, j);
	if (!ft_check_line(str + i + 1, set, size_x, size_y))
		return (0);
	return (ft_create_map(set, size_x, size_y));
}

char	*ft_get_file(const char *path)
{
	int			flux;
	long long	size;
	char		*buffer;

	buffer = malloc(BUFFSIZE);
	if (buffer == 0)
		return (0);
	if (path)
		flux = open(path, O_RDONLY);
	else
		flux = 0;
	if (flux == -1)
		return (0);
	size = read(flux, buffer, BUFFSIZE);
	if (size == -1)
		return (0);
	buffer[size] = 0;
	return (buffer);
}
