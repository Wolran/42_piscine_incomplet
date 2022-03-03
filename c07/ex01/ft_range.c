/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:00:58 by vmuller           #+#    #+#             */
/*   Updated: 2022/02/16 10:01:01 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tab;

	if (min >= max)
		return (0);
	i = max - min;
	tab = (int *) malloc(i);
	if (!tab)
		return (0);
	while (i >= 0)
	{
		tab[i] = max;
		max--;
		i--;
	}
	return (tab);
}
