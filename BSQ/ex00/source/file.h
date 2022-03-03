/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-fre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 01:20:33 by alde-fre          #+#    #+#             */
/*   Updated: 2022/02/22 01:20:34 by alde-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include "map.h" 

# define BUFFSIZE 1000000000

unsigned int	ft_strlen_c(char *str, char c);
char			*ft_check_line(char *str, char *set, int size_x, int size_y);
t_map			*ft_check_file(char *str);
char			*ft_get_file(const char *path);

#endif
