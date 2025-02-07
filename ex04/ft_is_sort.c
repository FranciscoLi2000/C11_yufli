#include <stdio.h>
#include <string.h>
int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}
int	compare_integers(int a, int b)
{
	return ((a > b) - (a < b));
}
int	main()
{
	int sorted_arr[] = {1, 2, 3, 4};
	int unsorted_arr[] = {56, 23, 25, 32};

	printf("%i\n", ft_is_sort(sorted_arr, 4, compare_integers));
	printf("%i\n", ft_is_sort(unsorted_arr, 4, compare_integers));
	return (0);
}
