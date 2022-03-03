/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:19:49 by alde-fre          #+#    #+#             */
/*   Updated: 2022/02/22 01:19:50 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "map.h"
#include "file.h"
#include "solve.h"

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen_c(str, 0));
}

void	ft_putsqr(t_map *map)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < map->max_size - 1)
	{
		x = 0;
		while (x < map->max_size - 1)
		{
			ft_set_map(map, map->square_x + x, map->square_y + y, map->set[2]);
			x++;
		}
		y++;
	}
}

void	ft_putmap(t_map *map)
{
	write(1, map->data, (map->width + 1) * map->height);
}

void	ft_solve_all(char *str, t_map *map)
{
	if (str)
	{
		map = ft_check_file(str);
		if (map)
		{
			if (ft_solve(map))
			{
				ft_putsqr(map);
				ft_putmap(map);
			}
			else
				ft_putstr("could not resolve\n");
			free(map);
		}
		else
			ft_putstr("map error\n");
		free(str);
	}
	else
		ft_putstr("map error\n");
}

int	main(int ac, char **av)
{
	int		i;
	char	*str;
	t_map	*map;

	map = 0;
	if (ac == 1)
	{
		str = ft_get_file(0);
		ft_solve_all(str, map);
		ft_putstr("\n");
	}
	i = 1;
	while (i < ac)
	{
		str = ft_get_file(av[i]);
		ft_solve_all(str, map);
		ft_putstr("\n");
		i++;
	}
	return (0);
}
