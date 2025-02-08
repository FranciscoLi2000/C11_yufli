#include <stdio.h>
void	ft_sort_string_tab(char **tab);
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}
void	ft_sort_string_tab(char **tab)
{
	char	*temp;
	int	j;
	int	swapped;

	if (tab == NULL || *tab == NULL)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		j = 0;
		while (tab[j + 1] != NULL)
		{
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
	}
}
int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
	{
		printf("Usage: %s <string1> <string2> ... <stringN>\n", argv[0]);
		return (1);
	}
	argv[argc] = NULL;
	ft_sort_string_tab(argv + 1);
	i = 1;
	while (i < argc)
	{
		printf("%s ", argv[i]);
		i++;
	}
	printf("\n");
	return (0);
}
