/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:04:57 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/02/06 17:32:05 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

typedef struct	s_flag
{
	int		minus;
	int		zero;
	int		dot;
	int		width;
	int		pre;
}				t_flag;

void	ft_init(t_flag *t)
{
	t->minus = 0;
	t->zero = 0;
	t->dot = 0;
	t->width = 0;
	t->pre = 0;
}

int		ft_parse(const char *fmt, t_flag *flag)
{
	if (*fmt == '-' || *fmt == '0')
	{
		if (*fmt++ == '-')
			flag->minus = 1;
		flag->zero = 1;
	}
	if (*fmt == '*' || (*fmt >= '1' && *fmt <= '9'))
	return (0);
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_flag		*flag;

	va_start(ap, fmt);
	flag = malloc(sizeof(t_flag));
	ft_init(flag);
	printf("%d\n", flag->minus);
	while (*fmt)
	{
		if (*fmt != '%')
		{
			write(1, fmt++, 1);
			continue;
		}
		fmt++;
		ft_parse(fmt, flag);
	}

	printf("%d\n", flag->minus);
	return (0);
}

int		main(void)
{
	ft_printf("Today is %-10.3d.\n", 6);
	return (0);
}
