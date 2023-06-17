# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/16 14:44:39 by hed-dyb           #+#    #+#              #
#    Updated: 2023/06/17 14:33:23 by hed-dyb          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBRARY = minishell.h
NAME = minishell
CC = cc 
RM = rm -f
FLAGS =  -Wall -Werror -Wextra -g
FILES = main.c 

OBJ = $(FILES:%.c=%.o)

all : $(NAME)

%.o : %.c $(LIBRARY)
	$(CC) $(FLAGS) -c $<

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -lreadline -o $(NAME)
	
clean :
	$(RM) a$(OBJ)

fclean : clean
	
	$(RM) $(NAME)

re : fclean all
	
	






