/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:20:56 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/02/08 20:31:02 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_num(va_list ap, t_flag *flag, char type)
{
	char	*src;
	char	*result;

	if (type == 'd' || type == 'i')
		src = ft_itoa(va_arg(ap, int));
	else if (type == 'u')
		src = ft_utoa_base(va_arg(ap, unsigned int), "0123456789");
	else if (type == 'x')
		src = ft_utoa_base(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (type == 'X')
		src = ft_utoa_base(va_arg(ap, unsigned int), "0123456789ABCDEF");

	result = ft_join_precision(ap, flag, src);
	src = result;
	result = ft_join_width(ap, flag, src);

	ft_putstr_fd(result, 1);
	free(result);
}
