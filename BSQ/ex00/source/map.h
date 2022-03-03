/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:32:12 by alde-fre          #+#    #+#             */
/*   Updated: 2022/02/22 01:32:13 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct s_map
{
	char			*data;
	unsigned int	width;
	unsigned int	height;
	char			*set;
	unsigned int	square_x;
	unsigned int	square_y;
	unsigned int	max_size;
}	t_map;

t_map	*ft_create_map(char *raw, unsigned int x, unsigned int y);
char	ft_get_map(t_map *map, unsigned int x, unsigned int y);
void	ft_set_map(t_map *map, unsigned int x, unsigned int y, char c);

#endif
