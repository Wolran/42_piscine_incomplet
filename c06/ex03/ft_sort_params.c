/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 04:24:30 by vmuller           #+#    #+#             */
/*   Updated: 2022/02/15 04:24:32 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] > s2[i] || s1[i] < s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	main(int arc, char **arv)
{
	int		i;
	int		j;
	char	*c;

	i = 1;
	while (i++ < arc)
	{
		j = 0;
		while (j++ < arc - i)
		{
			if (ft_strcmp(arv[j], arv[j + 1]) > 0)
			{
				c = arv[j + 1];
				arv[j + 1] = arv[j];
				arv[j] = c;
			}
		}
	}
	i = 1;
	while (i < arc)
	{
		ft_putstr(arv[i]);
		i++;
	}
}
