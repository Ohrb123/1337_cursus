# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/25 18:04:37 by oelharbi          #+#    #+#              #
#    Updated: 2024/03/25 18:15:37 by oelharbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAFGS = -I /usr/local/include -L /usr/local/lib  -lmlx -framework OpenGL -framework AppKit -O3

M_NAME = fractol

B_NAME = fractol_bonus

HEADER = mandatory/fractol.h

B_HEADER =bonus/fractol_bonus.h

OBJ = mandatory/draw.o mandatory/events.o mandatory/fractol.o mandatory/init_and_utils.o mandatory/parse.o 

B_OBJ = bonus/draw_bonus.o bonus/draw2_bonus.o bonus/events_bonus.o bonus/fractol_bonus.o bonus/init_and_utils_bonus.o bonus/parse_bonus.o\

all: $(M_NAME)

bonus : $(B_NAME)

$(M_NAME) : $(OBJ)
	$(CC) $(MLX_FLAFGS) $(CFLAGS) $(OBJ) -o $(M_NAME)

$(B_NAME) : $(B_OBJ)
	$(CC) $(CFLAGS) $(B_OBJ) -o $(B_NAME)

mandatory/%.o : mandatory%.c $(HEADER)
	$(CC) $(MLX_FLAFGS) $(CFLAGS) -c $< -o $@

bonus/%.o : bonus/%.c $(B_HEADER)
	$(CC) $(MLX_FLAFGS) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ) $(B_OBJ)

fclean: clean
	rm -f $(M_NAME) $(B_NAME)

re: fclean all 

.PHONY: clean
