/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:20:56 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/02/09 11:29:46 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type_num(va_list ap, t_flag *flag, char type)
{
	char	*src;
	char	*result;
	int		cnt;

	src = 0;
	if (type == 'd' || type == 'i')
		src = ft_itoa(va_arg(ap, int));
	else if (type == 'u')
		src = ft_uitoa_base(va_arg(ap, unsigned int), "0123456789");
	else if (type == 'x')
		src = ft_uitoa_base(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (type == 'X')
		src = ft_uitoa_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	result = ft_join_precision(flag, src);
	free(src);
	src = ft_strdup(result);
	free(result);
	result = ft_join_width(flag, src);
	free(src);
	ft_putstr_fd(result, 1);
	cnt = ft_strlen(result);
	free(result);
	return (cnt);
}

int		ft_type_address(va_list ap, t_flag *flag)
{
	char	*src;
	char	*result;
	int		cnt;

	src = ft_ultoa_base(va_arg(ap, unsigned long), "0123456789abcdef");
	result = ft_strjoin("0x", src);
	free(src);
	src = ft_strdup(result);
	free(result);
	result = ft_join_width(flag, src);
	free(src);
	ft_putstr_fd(result, 1);
	cnt = ft_strlen(result);
	free(result);
	return (cnt);
}

int		ft_type_char(va_list ap, t_flag *flag, char type)
{
	char	*src;
	char	*result;
	int		cnt;

	src = malloc(2);
	src[1] = 0;
	if (type == 'c')
		src[0] = va_arg(ap, int);
	else if (type == '%')
		src[0] = '%';
	result = ft_join_width(flag, src);
	free(src);
	ft_putstr_fd(result, 1);
	cnt = ft_strlen(result);
	free(result);
	return (cnt);
}

int		ft_type_str(va_list ap, t_flag *flag)
{
	char	*src;
	char	*result;
	int		cnt;

	src = ft_substr(va_arg(ap, char *), 0, flag->precision);
	result = ft_join_width(flag, src);
	free(src);
	ft_putstr_fd(result, 1);
	cnt = ft_strlen(result);
	free(result);
	return (cnt);
}
