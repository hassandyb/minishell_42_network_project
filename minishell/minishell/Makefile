# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/16 14:44:39 by hed-dyb           #+#    #+#              #
#    Updated: 2023/06/19 18:08:51 by hed-dyb          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBRARY = minishell.h
NAME = minishell
CC = cc 
RM = rm -f
FLAGS =  -Wall -Werror -Wextra -g -fsanitize=address
FILES = main.c utils_1.c protection.c

OBJ = $(FILES:%.c=%.o)

all : $(NAME)

%.o : %.c $(LIBRARY)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) -fsanitize=address -lreadline $(OBJ)  -o $(NAME)
	
clean :
	$(RM) $(OBJ)

fclean : clean
	
	$(RM) $(NAME)

re : fclean all
	
	






