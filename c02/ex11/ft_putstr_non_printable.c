/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 10:14:59 by vmuller           #+#    #+#             */
/*   Updated: 2022/02/06 10:15:06 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	hexa(int nbr)
{
	return ("0123456789abcdef"[nbr]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= 31 || str[i] == 127)
		{
			write (1, "\\", 1);
			ft_putchar(hexa((unsigned char)str[i] / 16));
			ft_putchar(hexa((unsigned char)str[i] % 16));
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
