/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 17:02:19 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/01/30 23:56:20 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;

	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
		{
			write(1, fmt++, 1);
			continue ;
		}
		if (*(++fmt) == 'c')
			ft_print_char(va_arg(ap, int));
		else if (*fmt == 's')
			ft_print_str(va_arg(ap, char *));
		else if (*fmt == 'p')
			ft_print_address(va_arg(ap, unsigned long));
		else if (*fmt == 'd' || *fmt == 'i')
			ft_putnbr_base_int(va_arg(ap, int), "0123456789");
		else if (*fmt == 'u')
			ft_putnbr_base_uint(va_arg(ap, unsigned int), "0123456789");
		else if (*fmt == 'x')
			ft_putnbr_base_uint(va_arg(ap, unsigned int), "0123456789abcdef");
		else if (*fmt == 'X')
			ft_putnbr_base_uint(va_arg(ap, unsigned int), "0123456789ABCDEF");
		else if (*fmt == '%')
			ft_print_char('%');
		fmt++;
	}
	return (0);
}

#include <stdio.h>
int		main(void)
{
	char				c = 'z';
	char				str[] = "apple";
	char				*p = &c;

	int					d_min = -2147483648;
	int					d_max = 2147483647;
	int					d_over = d_max + 1;

	unsigned int		u_min = 0;
	unsigned int		u_max = 4294967295;
	unsigned int		u_over = u_max + 1;

	printf("printf-------------\n");
	printf("%c, %s, %p, %p\n", c, str, str, p);
	printf("%d, %d, %d, %d\n", d_min, d_max, d_over, 0);
	printf("%u, %u, %u, %u\n", u_min, u_max, u_over, d_min);
	printf("%x, %x, %x\n", u_min, u_max, u_over);
	printf("%X, %X, %X\n", u_min, u_max, u_over);

	ft_printf("\nft_printf----------\n");
	ft_printf("%c, %s, %p, %p\n", c, str, str, p);
	ft_printf("%d, %d, %d, %d\n", d_min, d_max, d_over, 0);
	ft_printf("%u, %u, %u, %u\n", u_min, u_max, u_over, d_min);
	ft_printf("%x, %x, %x\n", u_min, u_max, u_over);
	ft_printf("%X, %X, %X\n", u_min, u_max, u_over);

	return (0);
}
