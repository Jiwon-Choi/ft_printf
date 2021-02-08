/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 20:37:53 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/02/08 20:30:03 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_zero_minus(const char **fmt, va_list ap, t_flag *flag)
{
	while (**fmt == '-' || **fmt == '0')
	{
		if (**fmt == '-')
			flag->left = 1;
		else
			flag->zero = 1;
		*fmt += 1;
	}
}

void	ft_parse_width(const char **fmt, va_list ap, t_flag *flag)
{
	int	tmp;

	if (**fmt == '*' || ft_isdigit(**fmt))
	{
		if (**fmt == '*')
		{
			tmp = va_arg(ap, int);
			if (tmp < 0)
			{
				flag->left = 1;
				tmp *= -1;
			}
			*fmt += 1;
		}
		else
			tmp = ft_atoi_double(fmt);
		flag->width = tmp;
	}
	if (!flag->left && flag->zero)
		flag->padding = '0';
}

void	ft_parse_precision(const char **fmt, va_list ap, t_flag *flag)
{
	if (**fmt == '*' || ft_isdigit(**fmt))
	{
		if (**fmt == '*')
		{
			flag->precision = va_arg(ap, int);
			*fmt += 1;
		}
		else
			flag->precision = ft_atoi_double(fmt);
	}
}

void	ft_parse(const char **fmt, t_flag *flag, va_list ap)
{
	ft_parse_zero_minus(fmt, ap, flag);
	ft_parse_width(fmt, ap, flag);
	if (**fmt == '.' && (*fmt)++)
		ft_parse_precision(fmt, ap, flag);
	if (ft_strchr("diuxX", **fmt))
		ft_type_num(ap, flag, **fmt);
	(*fmt)++;
}
