/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 02:52:55 by vmuller           #+#    #+#             */
/*   Updated: 2022/02/09 02:52:59 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	test;

	if (nb < 0)
	{
		test = nb * -1;
		ft_putchar('-');
	}
	else
		test = nb;
	if (test > 9)
		ft_putnbr(test / 10);
	ft_putchar('0' + (test % 10));
}
