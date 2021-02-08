/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:15:50 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/02/08 18:48:57 by jiwchoi          ###   ########.fr       */
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
	ft_printf("Hello [%-0*.*u], [%x], [%X].\n", -10, -3, 42, 42, 42);
	return (0);
}
