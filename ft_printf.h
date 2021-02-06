/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: “jiwcho <“jiwchoi@student.42seou>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:12:13 by “jiwcho         #+#    #+#             */
/*   Updated: 2021/02/06 18:17:23 by “jiwcho        ###   ########.fr       */
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
int			ft_atoi(const char *nptr);
int			ft_isdigit(int c);

#endif
