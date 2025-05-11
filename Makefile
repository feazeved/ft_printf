# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feazeved <feazeved@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/01 00:04:54 by feazeved          #+#    #+#              #
#    Updated: 2025/05/08 04:44:14 by feazeved         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
ft_flags.c \
ft_putsign.c \
ft_write_number.c \
ft_putnum.c \
ft_putstr.c \
ft_put_hex.c \
ft_write_hex.c \
ft_putpointer.c \
ft_specifier.c \
ft_putu.c \
ft_putchar.c \
ft_padding.c \
ft_hex_len.c \

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: all
%.o:%.c
	cc $(CFLAGS) -c $<
