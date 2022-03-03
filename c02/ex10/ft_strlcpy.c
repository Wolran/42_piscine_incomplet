/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 00:45:37 by vmuller           #+#    #+#             */
/*   Updated: 2022/02/06 00:45:43 by vmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size != 0)
	{
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

#include <bsd/string.h>
#include <stdio.h>
int main()
{
	char dest[56] = "loolololol";
	char src[] = "hello world";
	int size = 6;
	int	out = strlcpy(dest, src, size);
	printf("out:%d dest:%s", out, dest);
	printf("out:%d dest:%s", ft_strlcpy(dest, src, size), dest);
	 
}
