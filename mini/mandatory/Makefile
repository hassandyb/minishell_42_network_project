# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/16 14:44:39 by hed-dyb           #+#    #+#              #
#    Updated: 2023/07/11 11:14:06 by ataouaf          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBRARY = minishell.h exec.h
NAME = minishell
CC = cc 
RM = rm -rf
FLAGS =  -Wall -Werror -Wextra -g -fsanitize=address

OBJECTS = ./obj
EXEC = $(addprefix execution/, exec.c)
TOKENIZER = $(addprefix tokenizer/, tokenizer_1.c tokenizer_2.c spaces.c)
PARSER = parser.c
TOOLS = $(addprefix tools/, protection.c utils_1.c utils_2.c)
EXPANDER = $(addprefix expander/, env.c expand_vars.c split_spaces.c concatenate.c)

FILES = main.c $(TOKENIZER) $(TOOLS) $(PARSER) $(EXPANDER) $(EXEC)

OBJ = $(addprefix $(OBJECTS)/, $(FILES:%.c=%.o))

all : $(NAME)

$(OBJECTS)/%.o : %.c $(LIBRARY)
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) -lreadline $(OBJ)  -o $(NAME)
	
clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
