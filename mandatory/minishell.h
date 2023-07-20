/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:52:06 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/07/20 14:06:48 by hed-dyb          ###   ########.fr       */
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

typedef struct s_env
{
	char *var_name;
	char *value;
	struct s_env *next;
}t_env;

typedef struct s_red 
{
	t_type type;
	char *file;
	struct s_red *next;
}t_red;

typedef struct s_cmd
{
	char **comand;
	t_red *red;
	int ofd;
	int ifd;
	struct s_cmd *next;//,_cmd *next;
}t_cmd;


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
int ft_special_char (t_token *node);
void ft_unnecessary_spaces(t_token **t);

// parser
int ft_is_a_redirection(t_token *node);
int ft_check_close(t_token *t);
int ft_parsing(t_token *t);

//expander
void ft_expander(t_token **t, t_env **e, char **env, t_free *f);
t_env *ft_t_env_node(char *env_line, t_free *f);
void ft_add_back_t_env(t_env **e, t_env *node);
int ft_valid_var(char *tok);
void ft_begin_and_end(char *token, int *begin, int *end);
char *ft_get_var_value(t_env *e, char *var, t_free *f);
void ft_replace(t_token *node,t_env *e, t_free *f);
void ft_expand_var(t_token *t, t_env *e, t_free *f);
void ft_split_spaces(t_token **t, t_free *f);
void ft_add_new_to_t(t_token **t, t_token *temp, t_token *new);
int ft_is_wrd_qot(t_token *node);
char *ft_join_token(t_token *node1, t_token *node2, t_free *f);
void ft_if_its_inside(t_token *t, t_free *f);
void ft_concatenate(t_token **t, t_free *f);

//info
int ft_count(t_token *temp);
char **ft_comand_with_args(t_token *temp, t_free *f);
t_token *ft_next_part(t_token *temp);
void ft_protect(void *ptr, t_free *f);
void ft_add_back_t_red(t_red **r, t_red *node);
t_red *ft_create_t_red(t_token *temp, t_free *f);
t_cmd *ft_create_t_cmd(char **com, t_red *r, t_free *f);
void ft_add_back_t_cmd(t_cmd **cmd, t_cmd *node);
void ft_comand_info(t_cmd **cmd, t_token **t, t_free *f);

//utils
int ft_is_a_white_space(char c);
int ft_strlen(char *s);
int ft_isalpha(char c);
int ft_islnum(char c);
int ft_find_char(char *str, char c);
char	*ft_substr(char *s, int start, int len, t_free *f);
char *ft_strjoin(char *s1, char *s2, t_free *f);
int ft_count_words(char *str, char c);
char **ft_split(char *str, char c, t_free *f);
char *ft_strdup(char *str, t_free *f);

//free/protection functions
void ft_add_t_free(t_free **f, t_free *node);
void *ft_create_t_free(void *add, t_free *f);
void ft_free_all(t_free *f);
void ft_protection_2(char **to_check, void *optional, t_free *f);
void ft_protection(char *to_check, void *optional, t_free *f);
#endif

