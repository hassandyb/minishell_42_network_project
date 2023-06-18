# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/16 14:44:39 by hed-dyb           #+#    #+#              #
#    Updated: 2023/06/18 19:02:18 by hed-dyb          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBRARY = minishell.h
NAME = minishell
CC = cc 
RM = rm -f
FLAGS =  #-Wall -Werror -Wextra -g
FILES = main.c utils_1.c

OBJ = $(FILES:%.c=%.o)

all : $(NAME)

%.o : %.c $(LIBRARY)
	$(CC) $(FLAGS) -c $<

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -lreadline -o $(NAME)
	
clean :
	$(RM) $(OBJ)

fclean : clean
	
	$(RM) $(NAME)

re : fclean all
	
	






