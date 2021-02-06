/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 20:37:53 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/02/06 20:48:27 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parse_width_precision(const char **fmt, va_list ap)
{
	int		result;

	result = 0;
	if (**fmt == '*' || ft_isdigit(**fmt))
	{
		if (**fmt == '*')
		{
			result = va_arg(ap, int);
			*fmt += 1;
		}
		else
			result = ft_atoi(fmt);
	}
	return (result);
}
