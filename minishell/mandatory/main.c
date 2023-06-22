/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:51:40 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/06/22 17:32:25 by hed-dyb          ###   ########.fr       */
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
// char *ft_strjoin(char *new_token, char *to_add, t_free *f)
// {
// 	int i;
// 	int j;
// 	char *result;
	
// 	if(new_token == NULL)
// 	{
// 		new_token = malloc(1);
// 		new_token[0]= '\0';
// 	}
// 	i = -1;
// 	result = malloc((ft_strlen(new_token) + ft_strlen(to_add) + 1));
// 	ft_protection(result, NULL, f);
// 	while(new_token[++i])
// 		result[i] = new_token[i];
// 	j = 0;
// 	while(to_add[j])
// 	{
// 		result[i] = to_add[j];
// 		i++;
// 		j++;
// 	}
// 	result[i] = '\0';
// 	free(new_token);
// 	return result;
// }

// void ft_expand_word(t_token *node, t_env *e, t_free *f)
// {
// 	int i =0;
// 	// count ++;
// 	char *new_token;
// 	new_token = NULL;

// }
//-----------------------------
//first char should be _ or alphabet up and lower
/// sencend third  _ or alphabet up and lower or number


void ft_replace(t_token *node, t_env *e, t_free *f)
{
	char *new_token;
	int i;

	i = 0;
	while(node->token[i])
	{
		if(node->token[i] == '$' && (node->token[i + 1] == '_' || ft_is_alpha(node->token[i + 1]) == 1))
		 //node->token[i + 1] &&  (node->token[i + 1] == '_' || ft_is_alpha )
			//node->token = ft_  replace aaa$HOME+aa => aaa $HOME +aa ==>serach for home value ==>if it exit rplace home value =>>join all strings free.. free
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
		if(temp->type == _word || temp->type == _double_quote)
			ft_replace(temp, *e, f);
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
		// ft_print_t_token_linked_list(t);
		// ft_expander(&e, env, &t, f);

	}
	ft_free_all(f);	
}