/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 06:59:10 by vmuller           #+#    #+#             */
/*   Updated: 2022/02/13 06:59:11 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while ((i < n) && (src[i]))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ischarset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	ft_checkword(char *str, char *charset, int pos)
{
	int	i;

	i = 0;
	while (str[pos + i])
	{
		if (ischarset(str[pos + i], charset) || str[pos + i] == '\0')
			return (i);
		i++;
	}
	return (i);
}

int	ft_nbword(char *str, char *charset)
{
	int		count;
	int		i;
	char	a;

	i = 0;
	count = 0;
	a = charset[0];
	while (str[i])
	{
		if (!ischarset(str[i], charset) && ischarset(a, charset))
			count++;
		a = str[i];
		i++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		n;
	char	**tab;
	int		nbw;
	int		j;

	i = 0;
	n = 0;
	j = 0;
	nbw = ft_nbword(str, charset);
	tab = malloc(sizeof(char *) * (nbw + 1));
	if (!tab)
		return (0);
	while (str[i])
	{
		while (ischarset(str[i], charset))
			i++;
		n = ft_checkword(str, charset, i);
		tab[j] = malloc(sizeof(char) * (n + 1));
		if (!tab[j])
			return (0);
		tab[j] = ft_strncpy(tab[j], str + i, n);
		j++;
		i += n;
	}
	tab[j] = 0;
	return (tab);
}

#include <stdio.h>
int		main(int arc, char **av)
{
	int i = arc;
	arc = i;
	char *h = "salut a tous";
	char **tab = ft_split(h,"");
	
	for(int i = 0; tab[i]; i++)
	{
		printf("%s\n", tab[i]);
	}
}

