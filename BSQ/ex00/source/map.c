/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:32:05 by alde-fre          #+#    #+#             */
/*   Updated: 2022/02/22 01:32:07 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "file.h"
#include "map.h"

t_map	*ft_create_map(char *raw, unsigned int x, unsigned int y)
{
	t_map	*res;

	res = malloc(sizeof(t_map));
	res->data = raw + 3 + 1;
	res->width = x;
	res->height = y;
	res->set = raw;
	res->square_x = 0;
	res->square_y = 0;
	res->max_size = 0;
	return (res);
}

char	ft_get_map(t_map *map, unsigned int x, unsigned int y)
{
	if (x >= map->width || y >= map->height)
		return (0);
	return (map->data[x + y * (map->width + 1)]);
}

void	ft_set_map(t_map *map, unsigned int x, unsigned int y, char c)
{
	if (x >= map->width || y >= map->height)
		return ;
	map->data[x + y * (map->width + 1)] = c;
}
