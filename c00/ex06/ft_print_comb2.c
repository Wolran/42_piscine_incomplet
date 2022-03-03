/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 00:19:56 by vmuller           #+#    #+#             */
/*   Updated: 2022/02/05 07:42:07 by vmuller          ###   ########.fr       */
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

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a < 100)
	{
		b = a + 1;
		while (b < 100)
		{
			if (a < 10)
				write (1, "0", 1);
			ft_putnbr(a);
			write (1, " ", 1);
			if (b < 10)
				write (1, "0", 1);
			ft_putnbr(b);
			if (a != 98 || b != 99)
				write(1, ", ", 2);
			b++;
		}
		a++;
	}
}
