/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:15:50 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/02/08 21:45:45 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init(t_flag *t)
{
	t->left = 0;
	t->zero = 0;
	t->width = 0;
	t->precision = 0;
	t->padding = ' ';
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_flag		flag;

	va_start(ap, fmt);
	ft_init(&flag);
	while (*fmt)
	{
		if (*fmt != '%')
		{
			ft_putchar_fd(*fmt++, 1);
			continue;
		}
		fmt++;
		ft_parse(&fmt, &flag, ap);
		ft_init(&flag);
	}
	return (0);
}

int		main(void)
{
	int		num = 42;
	ft_printf("Hello [%-0*.*u], [%-05.3x], [%5.1X], [%p].\n", -10, -3, 42, 42, 42, &num);
	ft_printf("[%10.3s]\n", "abcdef");
	ft_printf("[%-2c] [%5%]\n", 'a');
	return (0);
}
