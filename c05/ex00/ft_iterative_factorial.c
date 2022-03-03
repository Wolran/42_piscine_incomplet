/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 02:14:34 by vmuller           #+#    #+#             */
/*   Updated: 2022/02/12 02:14:39 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_iterative_factorial(int nb)
{
	int	a;

	if (nb == 1 || nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	a = nb;
	while (a > 2)
	{
		nb = nb * (a - 1);
		a--;
	}
	return (nb);
}
