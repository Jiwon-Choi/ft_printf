/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:59:56 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/02/06 20:48:41 by jiwchoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_flag
{
	int		minus;
	int		zero;
	int		dot;
	int		width;
	int		precision;
}				t_flag;

int			ft_printf(const char *fmt, ...);
void		ft_init(t_flag *t);
int			ft_parse(const char *fmt, t_flag *flag, va_list ap);
int			ft_isspace(char ch);
static int	check_over_range(unsigned long long num, int sign);
int			ft_atoi(const char **nptr);
int			ft_isdigit(int c);
int			ft_parse_width_precision(const char **fmt, va_list ap);

#endif
