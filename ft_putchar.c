/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 22:33:54 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/01/30 23:02:19 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(int ch)
{
	write(1, &ch, 1);
}

void	ft_print_str(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_print_address(unsigned long nbr)
{
	write(1, "0x", 2);
	ft_putnbr_base_ulong(nbr, "0123456789abcdef");
}
