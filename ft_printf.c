/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:15:50 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/02/07 11:32:44 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_init(t_flag *t)
{
	t->minus = 0;
	t->zero = 0;
	t->width = 0;
	t->precision = 0;
	t->type = 0;
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
			write(1, fmt++, 1);
			continue;
		}
		fmt++;
		ft_parse(&fmt, &flag, ap);
	}

	printf("%d\n", flag.minus);
	printf("%d\n", flag.zero);
	printf("%d\n", flag.width);
	printf("%d\n", flag.precision);
	return (0);
}

int		main(void)
{
	ft_printf("Today is %*.*d.\n", -11, 4, 6);
	return (0);
}
