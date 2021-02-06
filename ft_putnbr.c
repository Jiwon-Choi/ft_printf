/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 22:10:48 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/01/30 22:56:47 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_div(long long nbr, int len, char *base)
{
	if (nbr == 0)
		return ;
	ft_div(nbr / len, len, base);
	write(1, &base[nbr % len], 1);
}

void	ft_putnbr_base_int(int nbr, char *base)
{
	int	len;

	len = ft_strlen(base);
	if (len == 0 || len == 1)
		return ;
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	else if (nbr < 0)
	{
		write(1, "-", 1);
		ft_div(-(nbr / len), len, base);
		write(1, &base[-(nbr % len)], 1);
	}
	else
	{
		ft_div(nbr / len, len, base);
		write(1, &base[nbr % len], 1);
	}
}

void	ft_putnbr_base_uint(unsigned int nbr, char *base)
{
	int	len;

	len = ft_strlen(base);
	if (len == 0 || len == 1)
		return ;
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	ft_div(nbr / len, len, base);
	write(1, &base[nbr % len], 1);
}

void	ft_putnbr_base_ulong(unsigned long nbr, char *base)
{
	int	len;

	len = ft_strlen(base);
	if (len == 0 || len == 1)
		return ;
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	ft_div(nbr / len, len, base);
	write(1, &base[nbr % len], 1);
}
