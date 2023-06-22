/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:51:40 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/06/22 12:36:33 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_print_t_token_linked_list(t_token *t)//
{
	if(t == NULL)
		printf("NULL\n");
		int i = 0;
	while(t)
	{
		printf("%d ==> %s  %s!\n", i, t->token, typeNames[t->type]);
		i++;
		t = t->next;
	}
	printf("\n\n");
}

void ft_print_t_env_linked_list(t_env *e)//
{
	if(e == NULL)
		printf("NULL\n");
		int i = 0;
	while(e)
	{
		printf("%d ==> %s      %s\n", i, e->var_name, e->value);
		i++;
		e = e->next;
	}
	printf("\n\n");
}

// tokenizer
// parcer
// expander
// conncater
// execution

//---------------------------

	// _white_space,  --
	// _pipe,
	// _append_output_re, //>>    --
	// _here_document,//  << --- 
	// _output_re,//  > -- 
	// _input_re,//   < -- 
	// _double_quote,//""
	// _single_quote, //''
	// _word,--
//----------------------------



// typedef struct s_env
// {
// 	char *var_name;
// 	char *value;
// 	struct s_env *next;
// }t_env;

//----------------
//   env_line = "USER=hed-dyb";

//   ABCD=EFGHI
//   0123456789
//   10 - 4 = 6


char	*ft_substr(char *s, int start, int len, t_free *f)
{
	char	*result;
	int	i;

	i = 0;
	if(s == NULL)
		return NULL;
	result = (char *) malloc(len + 1);
	ft_protection(result, NULL, f);
	ft_add_t_free(&f, ft_create_t_free(result, f));
	while (s[i + start] != '\0' && i < len)
	{
		result[i] = s[i + start];
		i++;
	}
	result[i] = '\0';
	return (result);
}

t_env *ft_t_env_node(char *env_line, t_free *f)
{
	t_env *node;
	int i;
	int len;
	
	i = 0;
	node = malloc(sizeof(t_env));
	if(node == NULL)
	{
		ft_free_all(f);
		exit (0);
	}
	ft_add_t_free(&f, ft_create_t_free(node, f));
	while(env_line[i])
	{
		if(env_line[i] == '=')
			break;
		i++;
	}
	len = ft_strlen(env_line);
	node->var_name = ft_substr(env_line, 0, i, f);
	node->value = ft_substr(env_line, i + 1, len - i - 1, f);
	node->next = NULL;
	return node;
}

void ft_add_back_t_env(t_env **e, t_env *node)
{
	t_env *temp;
	
	temp = *e;
	if(*e == NULL)
	{
		*e = node;
		return ;
	}
	while(temp)
	{
		if(temp->next == NULL)
			break ;
		temp = temp->next;
	}
	temp->next = node;
}
//---------------------------------

void ft_expand_word(t_token *node, t_env *e)
{
	int i =0;
	// count ++;
	char *new_token;
	while(node->token[i])
	{
		if(node->token[i] == '\'')
			i++;
		else if(node->token[i] == '$')
		{
			if(ft_var_exist(node->token, i, e) == 1)// in var exest you can compare the the var with the env list also if there is a match , the var shor end or there a is char who break it like any thing else deferent that number upper loer and under schoore
			{
				i = ft_replace
			}
				
		}
		else
			new_token = ft_strjoin(new_token, &node->token[i]);
		i++;
	}
}
void ft_expander(t_env **e, char **env, t_token **t, t_free *f)
{
	int i;
	t_token *temp;
	
	temp = *t;
	i = -1;
	if(*e == NULL)
	{
		while(env[++i])
			ft_add_back_t_env(e, ft_t_env_node(env[i], f));
			i++;
	}
	while(temp)
	{
		if(temp->type == _word)
			ft_expand_word(temp, *e);
		// else if(temp->type == _double_quote)
		// 	ft....
		// else if(temp->type == _single_quote)
		// 	ft....
	
		
		temp = temp->next;
	}
}



int main (int argc, char **argv, char  **env)
{
	t_token *t;
	t_free  *f;
	char *command;
	t_env *e;
	(void)argv;
	e = NULL;
	if(argc != 1)
		exit (0);
	while(1)
	{
		t = NULL;
		f = NULL;
		command = readline("minishell= ");
		if(command == NULL)
			exit (0);
		add_history(command);
		ft_create_tokens(&t, command, &f);
		if(ft_parsing(t) == 0)
		{
			ft_free_all(f);
			continue ;
		}
					ft_print_t_env_linked_list(e);
		ft_expander(&e, env, &t, f);
					ft_print_t_env_linked_list(e);
	}
	ft_free_all(f);	
}