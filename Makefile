# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwchoi <jiwchoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/30 21:38:42 by jiwchoi           #+#    #+#              #
#    Updated: 2021/02/09 11:19:41 by jiwchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

SRCS	= ft_join.c \
		  ft_parse.c \
		  ft_printf.c \
		  ft_to.c \
		  ft_type.c

BSRCS	=

OBJS	= $(SRCS:.c=.o)
BOBJS	= $(BSRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $<

$(NAME) : $(OBJS)
	make -C ./libft
	$(AR) $@ $^

bonus : $(BOBJS)
	$(AR) $(NAME) $^

all : $(NAME)

clean :
	$(RM) $(OBJS) $(BOBJS)

fclean : clean
	$(RM) $(NAME)

re : clean all

.PHONY : all clean fclean re bonus
