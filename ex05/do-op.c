#include <unistd.h>
#include <stdlib.h>
/* ft_atoi 将字符串转换为整数，处理前导符号和数字部分 */
int	ft_atoi(char *str)
{
	int	sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (int)(sign * result);
}
/* ft_putnbr 将整数转换为字符串并输出，处理负数和边界情况 */
void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}
/* 运算符函数：实现加、减、乘、除、模运算，除法和模运算中处理除数为零的情况 */
int	add(int a, int b)
{
	return (a + b);
}
int	subtract(int a, int b)
{
	return (a - b);
}
int	multiply(int a, int b)
{
	return (a * b);
}
int	divide(int a, int b)
{
	if (b == 0)
	{
		write(1, "Stop: division by zero\n", 23);
		exit(0);
	}
	return (a / b);
}
int	modulo(int a, int b)
{
	if (b == 0)
	{
		write(1, "Stop: modulo by zero\n", 21);
		exit(0);
	}
	return (a % b);
}

typedef int	(*operation)(int, int);

operation	get_operator(char op)
{
	switch (op)
	{
		case '+':
			return (add);
		case '-':
			return (subtract);
		case '*':
			return (multiply);
		case '/':
			return (divide);
		case '%':
			return (modulo);
		default:
			return (NULL);
	}
}
/* do-op 高阶函数：接受两个操作数、一个运算符以及一个函数指针
 * 调用相应的运算符函数并返回结果 */
int	do_op(int a, char op, int b, int (*operation)(int, int))
{
	if (operation == NULL)
	{
		write(1, "0\n", 2);
		return (0);
	}
	return (operation(a, b));
}
/*
int	do_op(int a, char op, int b)
{
	switch (op)
	{
		case '+':
			return (add(a, b));
		case '-':
			return (subtract(a, b));
		case '*':
			return (multiply(a, b));
		case '/':
			return (divide(a, b));
		case '%':
			return (modulo(a, b));
		default:
			write(1, "0\n", 2);
			return (0);
	}
} */
/* 主函数：检查参数有效性，转换操作数
 * 调用 do-op 函数处理运算，并输出结果或错误信息 */
int	main(int argc, char **argv)
{
	char	op;
	int	value1;
	int	value2;
	int	result;

	if (argc != 4)
		return (0);
	if (argv[2][0] == '\0' || argv[2][1] != '\0')
		return (0);
	value1 = ft_atoi(argv[1]);
	op = argv[2][0];
	value2 = ft_atoi(argv[3]);
	int (*operation)(int, int) = get_operator(op);
	result = do_op(value1, op, value2, operation);
	ft_putnbr(result);
	write(1, "\n", 1);
	return (0);
}
