/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 19:01:11 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/02/06 20:19:21 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int				ft_isspace(char ch)
{
	if (ch == ' ')
		return (1);
	if (ch == '\f')
		return (1);
	if (ch == '\n')
		return (1);
	if (ch == '\r')
		return (1);
	if (ch == '\t')
		return (1);
	if (ch == '\v')
		return (1);
	return (0);
}

static int		check_over_range(unsigned long long num, int sign)
{
	if (num > LLONG_MAX - 1 && sign == -1)
		return (0);
	if (num > LLONG_MAX && sign == 1)
		return (-1);
	return (num * sign);
}

int				ft_atoi(const char **nptr)
{
	int					i;
	int					sign;
	long long			num;

	i = 0;
	sign = 1;
	num = 0;
	while (ft_isspace(**nptr))
		*nptr += 1;
	if (**nptr == '-' || **nptr == '+')
	{
		if (**nptr == '-')
			sign *= -1;
		i++;
	}
	while (**nptr >= '0' && **nptr <= '9')
	{
		num *= 10;
		num += (*(*nptr)++ - '0');
	}
	return (check_over_range(num, sign));
}
