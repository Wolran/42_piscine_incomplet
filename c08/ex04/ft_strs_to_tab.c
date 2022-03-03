/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:59:07 by vmuller           #+#    #+#             */
/*   Updated: 2022/02/23 13:59:10 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*n;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(src);
	n = malloc(sizeof(char) * (size + 1));
	if (n == 0)
		return (0);
	while (src[i])
	{
		n[i] = src[i];
		i++;
	}
	n[i] = '\0';
	return (n);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			n;

	n = 0;
	tab = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!tab)
		return (0);
	while (n < ac)
	{
		tab[n].size = ft_strlen(av[n]);
		tab[n].str = av[n];
		tab[n].copy = ft_strdup(av[n]);
		n++;
	}
	tab[n].str = '\0';
	return (tab);
}
