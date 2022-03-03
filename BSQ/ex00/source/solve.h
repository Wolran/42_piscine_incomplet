/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:24:13 by alde-fre          #+#    #+#             */
/*   Updated: 2022/02/22 01:24:15 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SOLVE_H
# define SOLVE_H

# include "map.h"

int	ft_check_square(t_map *map, unsigned int x, unsigned int y);
int	ft_solve(t_map *map);

#endif
