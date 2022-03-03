// nombre de mots
// nombre de cqrqc de mots
// charset
// copy
// salut a tous c moi uuuuu

#include <stdlib.h>

#include <stdio.h>
char	*ft_strncpy(char *dest, char *str, int n)
{
	int i = 0;
	while (str[i] || i <= n)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 10;
	return (dest);
}
int	check_carac(char c)
{
	if (c == 32 || c == 9 || c == 10)
		return (0);
	return (1);
} 

int	nb_word(char *str)
{
	int i = 0;
	char c = 32;
	int count = 0;
	while (str[i])
	{
		if(!check_carac(str[i]) && check_carac(str[i]) != c)
			count++;
		c = check_carac(str[i]);
		i++;
	}
	return (i);
}

int	nb_caracw(char *str, int index)
{
	int i = 0;
	while (str[index + i])
	{
		if (check_carac(str[index + i]) || str[index + i])
			return (i);
		i++;
	}
	return (i);
}



char	**ft_split(char *str)
{
	char **tab;
	int	i = 0;
	int	n = 0;
	int	j = 0;
	int	nbw = nb_word(str);
	printf("1\n");
	tab = malloc(sizeof(char *) * (nbw + 1));
	if (!tab)
		return (0);
	while (str[i])
	{
		while (check_carac(str[i]))
			i++;
		printf("2\n");
		j = nb_caracw(str, i);
		printf("gg\n");
		tab[n] = malloc(sizeof(char) * (j + 1));
		printf("5\n");
		tab[n] = ft_strncpy(tab[n],str + i, j);
		n++;
		i += j;
	}
	printf("aaaaa\n");
	tab[n] = 0;
	return (tab);
	
}

int main()
{
	char **tab;
	char str[] = "salut a tous c moi	et moi    u";
	tab = ft_split(str);
	int n = 0;
	while (tab[n])
	{
		printf("%s\n", tab[n]);
		n++;
	}
}
