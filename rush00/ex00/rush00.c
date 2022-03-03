/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 23:08:38 by vmuller           #+#    #+#             */
/*   Updated: 2022/02/05 01:26:27 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	displaybord(int yincr, int xincr, int y, int x)
{	
	if ((xincr == 0 && yincr == 0) || (xincr == 0 && yincr == y - 1))
		ft_putchar('o');
	else if (xincr == x - 1 && yincr == 0)
		ft_putchar('o');
	else if (xincr == x - 1 && yincr == y - 1)
		ft_putchar('o');
	else if ((xincr >= 0 && xincr < x - 1) && (yincr == 0))
		ft_putchar('-');
	else if ((xincr >= 0) && (xincr < x - 1) && (yincr == y - 1))
		ft_putchar('-');
	else if ((xincr == 0) && (yincr > 0) && (yincr < y - 1))
		ft_putchar('|');
	else if ((xincr == x - 1) && (yincr > 0) && (yincr < y - 1))
		ft_putchar('|');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	yincr;
	int	xincr;

	yincr = 0;
	if (x > 0 && y > 0)
	{	
		while (yincr <= y)
		{
			xincr = 0;
			while (xincr <= x)
			{
				displaybord(yincr, xincr, y, x);
				xincr++;
			}
			if (yincr != y - 1)
				ft_putchar('\n');
			yincr++;
		}
	}
}
