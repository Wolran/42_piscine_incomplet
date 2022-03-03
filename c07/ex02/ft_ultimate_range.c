/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:40:37 by vmuller           #+#    #+#             */
/*   Updated: 2022/02/16 12:40:39 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*tab;
	int	j;

	if (min >= max)
		return (0);
	i = max - min;
	tab = (int *) malloc(i);
	if (!tab)
		return (-1);
	j = -1;
	while (i >= 0)
	{
		tab[i] = max;
		max--;
		i--;
		j++;
	}
	*range = tab;
	return (j);
}
