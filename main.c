/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:04:57 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/02/06 16:43:04 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

typedef struct	s_flag
{
	int		minus;
	int		zero;
	int		dot;
	int		width;
	int		pre;
}				t_flag;

int		ft_parse(char *fmt, t_flag *flag)
{
	if (*fmt == '-' || *fmt == '0')
	{
		if (*fmt++ == '-')
			flag->minus = 1;
		flag->zero = 1;
	}
}

int		ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_flag		*flag;

	va_start(ap, fmt);
	flag = malloc(sizeof(t_flag));
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
}

int		main(void)
{
	ft_printf("Today is %-10.3d.\n", 6);
	return (0);
}
