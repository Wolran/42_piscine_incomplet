/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:20:31 by vmuller           #+#    #+#             */
/*   Updated: 2022/02/16 16:20:33 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	comparebase(char *base)
{
	int	i;
	int	j;
	int	flag;

	flag = 1;
	i = 0;
	while (base[i] && flag)
	{
		if (base[i] == '-' || base[i] == '+'
			|| (base[i] >= 9 && base[i] <= 13) || base[i] == 32)
			flag = 0;
		j = 0;
		while (base[j] && flag)
		{
			if (base[i] == base[j] && i != j)
				flag = 0;
			j++;
		}
		i++;
	}
	return (flag);
}

int	convb(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (str == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	n;
	int	h;
	int	baselen;

	i = 0;
	n = 1;
	h = 0;
	while (str[i] <= 32 || str[i] == 127)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = n * -1;
		i++;
	}
	if (comparebase(base) == 0)
		return (0);
	baselen = ft_strlen(base);
	while (convb(str[i], base) != -1)
	{
		h = h * baselen + convb(str[i], base);
		i++;
	}
	return (h * n);
}
