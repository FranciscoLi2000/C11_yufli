#include <stdio.h>
#include <stdlib.h>
/* 高阶函数：对数组每个元素应用f，返回新数组 */
int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	*result;
	int	i;

	result = (int *)malloc(length * sizeof(int));
	if (!result)
		return (NULL);
	i = 0;
	while (i < length)
	{
		result[i] = f(tab[i]);/* 依次执行 operation，保证顺序 */
		i++;
	}
	return (result);
}
/* 示例操作函数：返回元素的平方 */
int	square(int x)
{
	return (x * x);
}
/* 示例操作函数：加一 */
int	increment(int x)
{
	return (x + 1);
}
int	main()
{
	int numbers[5] = {1, 2, 3, 4, 5};
	int *squared = ft_map(numbers, 5, square);
	int *incremented = ft_map(numbers, 5, increment);

	if (squared && incremented)/* 确保内存分配成功 */
	{
		printf("Square: ");
		for (int i = 0; i < 5; i++)
			printf("%d ", squared[i]);
		printf("\n");
		printf("Add: ");
		for (int i = 0; i < 5; i++)
			printf("%d ", incremented[i]);
		printf("\n");
	}
	free(squared);
	free(incremented);
	return (0);
}
