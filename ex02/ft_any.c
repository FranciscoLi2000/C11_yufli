#include <stdlib.h>
/* 高阶函数：对字符串数组的每个元素调用 `operation`，返回 1 或 0 */
int	ft_any(char **tab, int(*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i] != NULL)/* 遍历以 NULL 结尾的数组 */
	{
		if (f(tab[i]) != 0)/* 只要有一个返回值 ≠ 0，就立即返回 1 */
			return (1);
		i++;
	}
	return (0);
}
/* 低阶函数：调用 atoi 转换字符串为整数，并返回该整数 */
int	str_to_int(char *str)
{
	return (atoi(str)); /* 直接调用 atoi，返回转换后的整数 */
}
#include <stdio.h>
int	main()
{
	char *numbers1[] = {"0", "0", "0", NULL};  /* 全部转换为 0 */
	char *numbers2[] = {"0", "42", "0", NULL}; /* 42 转换后是非零 */
	char *numbers3[] = {"-10", "0", "123", NULL}; /* -10 和 123 都是非零 */
	char *numbers4[] = {"hello", "world", NULL};  /* "hello" 和 "world" 转换后是 0（无效转换）*/
	printf("Array1: %d\n", ft_any(numbers1, str_to_int));
	printf("Array2: %d\n", ft_any(numbers2, str_to_int));
	printf("Array3: %d\n", ft_any(numbers3, str_to_int));
	printf("Array4: %d\n", ft_any(numbers4, str_to_int));
	return (0);
}
