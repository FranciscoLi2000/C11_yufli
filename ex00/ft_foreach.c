#include <stdio.h>
#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
/* 高阶函数：对数组的每个元素执行f函数 */
void	ft_foreach(int *tab, int length, void(*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);/* 调用传入的函数 */
		if (i < length - 1)
			ft_putchar(' ');
		i++;
	}
}
/* 示例操作函数：打印元素 */
void	print_element(int x)
{
	printf("Element: %d\n", x);
}
/* 示例操作函数：计算平方并打印 */
void	square(int x)
{
	printf("The square of %d is %d\n", x, x * x);
}
void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}
int	main()
{
	int tab[1337];
	int numbers[] = {1, 2, 3, 4, 5};
	int length = sizeof(numbers) / sizeof(numbers[0]);

	printf("=== Print the elements of array ===\n");
	ft_foreach(numbers, length, print_element); /* 传入 print_element */
	printf("\n=== calculate the square ===\n");
	ft_foreach(numbers, length, square); /* 传入 square */
	printf("\n=== print the number ===\n");
	for (int i = 0; i < 1337; i++)
		tab[i] = i + 1;
	ft_foreach(tab, 1337, &ft_putnbr);
	printf("\n");

	return (0);
}
