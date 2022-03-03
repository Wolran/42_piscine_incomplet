/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 00:24:33 by vmuller           #+#    #+#             */
/*   Updated: 2022/02/06 00:24:38 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*checkcarac(char *str, int i)
{
	if (str[i - 1] >= 32 && str[i - 1] <= 47)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
	}
	else if (str[i - 1] >= 58 && (str[i -1] <= 64))
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
	}
	else if (str[i - 1] >= 91 && str[i - 1] <= 96)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
	}
	else if (str[i - 1] >= 123 && str[i - 1] <= 126)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'A') && (str[i] <= 'Z'))
			str[i] = str[i] + 32;
		i++;
	}
	if ((str[0] >= 'a') && (str[0] <= 'z'))
		str[0] = str[0] - 32;
	i = 1;
	while (str[i])
	{
		checkcarac(str, i);
		i++;
	}
	return (str);
}
