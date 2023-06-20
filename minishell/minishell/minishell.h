/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:52:06 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/06/20 12:48:47 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>


static char* typeNames[] = {
    "_white_space",
    "_pipe",
    "_append_output_re",
    "_here_document",
    "_output_re",
    "_input_re",
    "_double_quote",
    "_single_quote",
    "_word"
};

typedef struct s_free
{
	void *address;
	struct s_free *next;
}t_free;

typedef enum e_type
{
	_white_space,
	_pipe,
	_append_output_re, //>>
	_here_document,//  <<
	_output_re,//  >
	_input_re,//   <
	_double_quote,//""
	_single_quote, //''
	_word,
}	t_type;


typedef struct s_token
{
	char	*token;
	t_type	type;// will take a vaule from the t_type evry time
	struct	s_token *next;
	struct	s_token *previous;
	
}t_token;

//tokenizer (tokenization) functions

//part 1
t_token *ft_create_node(char *tok, int type_, t_free **f, char *command);
void ft_add_back(t_token **t, t_token *node);
int ft_space_or_pipe(t_token **t, char *command, int i, t_free **f);
int ft_redirections(t_token **t, char *command, int i, t_free **f);
int ft_end_of_word(char *command, int i);
int ft_is_a_word(t_token **t, char *command, int i, t_free **f);
int ft_char_indice(char *command, int i, char c);
int ft_double_qoute(t_token **t, char *command, int i, t_free **f);
int ft_single_quote(t_token **t,char *command, int i, t_free **f);
void ft_create_tokens(t_token **t, char *command, t_free **f);
//part 2 remove an neccecery tabs


int ft_is_a_white_space(char c);
int ft_strlen(char *s);
void ft_add_address(t_free **ptr, t_free *new);

//free/protection functions
void ft_add_t_free(t_free **f, t_free *node);
void *ft_create_t_free(void *add, t_free *f);
void ft_free_all(t_free *f);
void ft_protection(char *to_check, char *command, t_free *f);
#endif

