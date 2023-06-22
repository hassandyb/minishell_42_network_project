# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/16 14:44:39 by hed-dyb           #+#    #+#              #
#    Updated: 2023/06/22 11:45:18 by hed-dyb          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBRARY = minishell.h
NAME = minishell
CC = cc 
RM = rm -f
FLAGS =  -Wall -Werror -Wextra -g -fsanitize=address

TOKENIZER = $(addprefix tokenizer/, tokenizer_1.c tokenizer_2.c spaces.c)
PARSER = parser.c
TOOLS = $(addprefix tools/, protection.c utils_1.c)

FILES = main.c $(TOKENIZER) $(TOOLS) $(PARSER)

OBJ = $(FILES:%.c=%.o)

all : $(NAME)

%.o : %.c $(LIBRARY)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) -lreadline $(OBJ)  -o $(NAME)
	
clean :
	$(RM) $(OBJ)

fclean : clean
	
	$(RM) $(NAME)

re : fclean all
	
	






