#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

char	*ft_itoabase(int nb, char *base)
{
	int i = nb;
	int count = 0;
	char *str;
	int baselen = ft_strlen(base);

	if (i < 0)
	{
		count++;
		i = i * -1;
	}
	while (i != 0)
	{
		i = i / baselen;
		count++;
	}
	str = malloc(sizeof(char) * (count + 1));
	i = nb;
	str[count] = 0;
	while (count > 0 && str[count - 1] != '-')
	{
		if (i < 0)
		{
			str[0] = '-';
			i = i * -1;
		}
		else 
		{
			count--;
			str[count] = (i % baselen) + (i / base);
			i /= baselen;
		}
	}
	return (str);
}

#include <stdio.h>
int main()
{
	char *base = "01";
	char *str = ft_itoabase(42,base);
	printf("%s", str);
	return 0;
}
