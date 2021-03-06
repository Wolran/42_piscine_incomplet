/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:08:12 by vmuller           #+#    #+#             */
/*   Updated: 2022/02/09 12:08:14 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
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
		if (base[i] == '-' || base[i] == '+')
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

void	ft_putnbr_recurs(int nbr, char *base, unsigned int i)
{
	unsigned int	test;

	if (nbr < 0)
	{
		test = nbr * -1;
		ft_putchar('-');
	}
	else
		test = nbr;
	if (test >= i)
		ft_putnbr_recurs(test / i, base, i);
	ft_putchar(base[test % i]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	i;

	if (!base[0])
		return ;
	else if (!base[1])
		return ;
	i = ft_strlen(base);
	if (comparebase(base))
		ft_putnbr_recurs(nbr, base, i);
}
