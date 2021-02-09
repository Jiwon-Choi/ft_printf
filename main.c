
#include <stdio.h>
int		main(void)
{
	int		num = 42;
	int a, b;
	a = printf("Hello [%-0*.*u], [%-05.3x], [%5.1X].\n", -10, -3, 42, 42, 42);
	b = ft_printf("Hello [%-0*.*u], [%-05.3x], [%5.1X].\n", -10, -3, 42, 42, 42);
	printf("%d %d \n", a, b);
	a = printf("[%p]\n", &num);
	b = ft_printf("[%p]\n", &num);
	printf("%d %d \n", a, b);
	a = printf("[%10.0s]\n", "abcdef");
	b = ft_printf("[%10.0s]\n", "abcdef");
	printf("%d %d \n", a, b);
	a = printf("[%-2c] [%5%]\n", 'a');
	b = ft_printf("[%-2c] [%5%]\n", 'a');
	printf("%d %d \n", a, b);
	return (0);
}
