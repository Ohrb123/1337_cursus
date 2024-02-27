# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 17:03:14 by oelharbi          #+#    #+#              #
#    Updated: 2023/12/05 11:55:04 by oelharbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

CC = cc

OBJ = ft_printf.o ft_printf_utils.o\

HEADER = ft_printf.h

all : $(NAME)

$(NAME) : $(OBJ)
	ar rcs $@ $^
	
%.o : %.c  $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean :
	rm -rf $(OBJ) $(BONUS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean re