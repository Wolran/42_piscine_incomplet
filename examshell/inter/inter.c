#include <unistd.h>

void ftputchar(char c)
{
	write(1, &c, 1);
} 

int checkgood(char *src, char srcomp, int count)
{
	int	i = 0; 
	while (i < count)
	{
		if (src[i] == srcomp)
			return (0);
		i++;
	}
	return (1);
}

int main(int arc, char **arv)
{
	int i = 0;
	int j = 0;
	
	if (arc == 3)
	{
		while (arv[1][i])
		{
			j = 0;
			while(arv[2][j])
			{
				if (arv[1][i] == arv[2][j])
				{
					if (checkgood(arv[1], arv[1][i], i))
					{
						ftputchar(arv[1][i]);
						break;
					}
				}
				j++;
			}
			i++;
		}
	}
	write(1,"\n",1);
	return (0);
}
