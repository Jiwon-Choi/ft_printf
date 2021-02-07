/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwchoi <jiwchoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:59:56 by jiwchoi           #+#    #+#             */
/*   Updated: 2021/02/07 16:14:38 by jiwchoi          ###   ########.fr       */
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
	int		width;
	int		precision;
	char	type;
}				t_flag;

int			ft_printf(const char *fmt, ...);

size_t		ft_strlen(const char *s);
void		ft_div(long long nbr, int len, char *base);

void		ft_putnbr_base_int(int nbr, char *base);
void		ft_putnbr_base_uint(unsigned int nbr, char *base);
void		ft_putnbr_base_ulong(unsigned long nbr, char *base);

void		ft_print_char(int ch);
void		ft_print_str(char *str);
void		ft_print_address(unsigned long nbr);

void		ft_init(t_flag *t);

void		ft_parse(const char **fmt, t_flag *flag, va_list ap);
void		ft_parse_zero_minus(const char **fmt, va_list ap, t_flag *flag);
void		ft_parse_width(const char **fmt, va_list ap, t_flag *flag);
void		ft_parse_precision(const char **fmt, va_list ap, t_flag *flag);

int			ft_isspace(char ch);
static int	check_over_range(unsigned long long num, int sign);
int			ft_atoi_printf(const char **nptr);

int			ft_isdigit(int c);

static int		get_len(long long n);
char			*ft_itoa(int n);
#endif
