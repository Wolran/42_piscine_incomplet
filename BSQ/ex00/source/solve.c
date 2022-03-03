/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:24:08 by alde-fre          #+#    #+#             */
/*   Updated: 2022/02/22 01:24:10 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "solve.h"
#include "map.h"

int	ft_check_square(t_map *map, unsigned int x, unsigned int y)
{
	unsigned int	i;
	unsigned int	size;

	size = -1;
	while (++size || 1)
	{
		i = -1;
		while (++i < size)
		{
			if (ft_get_map(map, x + size - 1, y + i) == map->set[1]
				|| ft_get_map(map, x + i, y + size - 1) == map->set[1]
				|| x + i >= map->width || y + i >= map->height)
			{
				if (size > map->max_size)
				{
					map->square_x = x;
					map->square_y = y;
					map->max_size = size;
					return (1);
				}
				return (0);
			}
		}
	}
	return (0);
}

int	ft_solve(t_map *map)
{
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y + map->max_size < map->height)
	{
		x = 0;
		while (x + map->max_size < map->width)
		{
			ft_check_square(map, x, y);
			x++;
		}
		y++;
	}
	return (map->max_size);
}
