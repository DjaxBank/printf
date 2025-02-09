# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbank <dbank@student.codam.nl>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/26 19:24:02 by dbank             #+#    #+#              #
#    Updated: 2024/10/29 16:24:36 by dbank            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ft_printf.c write_functions.c
OBJS = $(SRC:%.c=%.o)
CC = cc
CCFLAGS = -Wall -Wextra -Werror

all: $(NAME) 

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS) 

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all