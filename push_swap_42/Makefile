# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 17:03:14 by oelharbi          #+#    #+#              #
#    Updated: 2024/02/24 00:01:31 by oelharbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

M_NAME = push_swap

B_NAME = checker

HEADER = mandatory/push_swap.h

B_HEADER =bonus/checker_bonus.h

OBJ = mandatory/algorithm/algo_utils.o mandatory/algorithm/algo_utils1.o mandatory/algorithm/algo_utils2.o\
	mandatory/algorithm/sort_custom.o mandatory/moves/push.o mandatory/moves/reverse_rotate.o mandatory/moves/rotate.o\
	mandatory/moves/swap.o mandatory/parse/errors.o mandatory/parse/ft_split.o mandatory/parse/parse.o\
	mandatory/parse/split_utils.o mandatory/parse/utils.o mandatory/push_swap.o\

B_OBJ = bonus/checker_moves/push_bonus.o bonus/checker_moves/reverse_rotate_bonus.o bonus/checker_moves/rotate_bonus.o\
	bonus/checker_moves/swap_bonus.o bonus/checker_parse/errors_bonus.o bonus/checker_parse/ft_split_bonus.o\
	bonus/checker_parse/parse_bonus.o bonus/checker_parse/split_utils_bonus.o bonus/checker_parse/utils_bonus.o\
	bonus/get_next_line/get_next_line_bonus.o bonus/get_next_line/get_next_line_utils_bonus.o bonus/checker_bonus.o\

all: $(M_NAME)

bonus : $(B_NAME)

$(M_NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(M_NAME)

$(B_NAME) : $(B_OBJ)
	$(CC) $(CFLAGS) $(B_OBJ) -o $(B_NAME)

mandatory/algorithm/%.o : mandatory/algorithm/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	
mandatory/parse/%.o : mandatory/parse/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	
mandatory/moves/%.o : mandatory/moves/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus/checker_moves/%.o : bonus/checker_moves/%.c $(B_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	
bonus/checker_parse/%.o : bonus/checker_parse/%.c $(B_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	
bonus/get_next_line/%.o : bonus/get_next_line/%.c $(B_HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJ) $(B_OBJ)

fclean: clean
	rm -f $(M_NAME) $(B_NAME)

re: fclean all 

.PHONY: clean
