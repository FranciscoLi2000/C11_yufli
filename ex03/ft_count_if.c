#include <stdlib.h>
/* 高阶函数：如果所有数组元素的f返回值都 ≠ 0，则返回数组长度；否则返回 0 */
int	ft_count_if(char **tab, int length, int(*f)(char *))
{
	int	i;

	i = 0;
	while (i < length)
	{
		if (f(tab[i]) == 0)
			return (0);
		i++;
	}
	return (length);
}
#include <stdio.h>
/* 低阶函数示例1：字符串转整数，检查是否 ≠ 0 */
int	str_to_int(char *str)
{
	return (atoi(str));  /* atoi 返回 0 表示转换失败或值为 0 */
}
/* 低阶函数示例2：检查字符串是否为空 */
int	is_not_empty(char *str)
{
	return (str[0] != '\0');  /* 空字符串返回 0，非空返回 1 */
}
int	main()
{
	char *numbers1[] = {"1", "-5", "42", "10", "99"};
	char *numbers2[] = {"0", "42", "-3", "7", "100"};
	char *strings1[] = {"hello", "world", "test", "C"};
	char *strings2[] = {"hello", "", "test"};
	int size1 = sizeof(numbers1) / sizeof(numbers1[0]);
	int size2 = sizeof(numbers2) / sizeof(numbers2[0]);
	int size3 = sizeof(strings1) / sizeof(strings1[0]);
	int size4 = sizeof(strings2) / sizeof(strings2[0]);
	printf("numbers1 (全非零): %d\n", ft_count_if(numbers1, size1, str_to_int));
	printf("numbers2 (含0): %d\n", ft_count_if(numbers2, size2, str_to_int));
	printf("strings1 (全非空): %d\n", ft_count_if(strings1, size3, is_not_empty));
	printf("strings2 (含空): %d\n", ft_count_if(strings2, size4, is_not_empty));
	return (0);
}
