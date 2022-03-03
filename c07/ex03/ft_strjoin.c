/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:56:52 by vmuller           #+#    #+#             */
/*   Updated: 2022/02/16 14:56:54 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strcat(char *dest, char *src, char *sep)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (sep[j])
	{
		dest[i] = sep[j];
		j++;
		i++;
	}
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*tab;
	char	*nul;

	if (size == 0)
	{
		nul = (char)malloc(sizeof(char));
		nul[0] = 0;
		return (nul);
	}
	tab = (char *)malloc(size + ft_strlen(sep));
	if (!*strs)
		return (0);
	ft_strcat(tab, strs[0], "");
	i = 1;
	while (i < size)
	{
		ft_strcat(tab, strs[i], sep);
		i++;
	}
	return (tab);
}
