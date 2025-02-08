#include <stdio.h>
void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *));
int	ft_strcmp(char *s1, char *s2);
void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	char	*temp;
	int	swapped;
	int	j;

	if (tab == NULL || *tab == NULL || cmp == NULL)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		j = 0;
		while (tab[j + 1] != NULL)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
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
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
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
	ft_advanced_sort_string_tab(argv + 1, ft_strcmp);
	i = 1;
	while (i < argc)
	{
		printf("%s ", argv[i]);
		i++;
	}
	printf("\n");
	return (0);
}
