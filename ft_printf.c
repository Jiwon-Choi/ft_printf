/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:15:50 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/02/06 18:54:02 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_init(t_flag *t)
{
	t->minus = 0;
	t->zero = 0;
	t->dot = 0;
	t->width = 0;
	t->precision = 0;
}

int		ft_parse(const char *fmt, t_flag *flag, va_list ap)
{
	if (*fmt == '-' || *fmt == '0')
	{
		if (*fmt++ == '-')
			flag->minus = 1;
		flag->zero = 1;
	}
	if (*fmt == '*' || ft_isdigit(*fmt))
	{
		if (*fmt == '*')
			flag->width = va_arg(ap, int);
		else
			flag->width = ft_atoi(fmt);
	}
	// atoi 이후 포인터 이동 필요
	/*
	if (*fmt == '.')
	{
		if (*fmt == '*' || ft_isdigit(*fmt))
		{
			if (*fmt == '*')
				flag->precision = va(ap, int);
			else
				flag->precision = ft_atoi(fmt);
		}
	}*/
	return (0);
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
		ft_parse(fmt, &flag, ap);
	}

	printf("%d\n", flag->minus);
	printf("%d\n", flag->width);
	return (0);
}

int		main(void)
{
	ft_printf("Today is %-10.3d.\n", 6);
	return (0);
}
