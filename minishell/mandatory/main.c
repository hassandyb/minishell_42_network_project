/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:51:40 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/06/21 15:35:11 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_print_linked_list(t_token *t)
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

void ft_protection(char *to_check, char *optional, t_free *f)
{
	if(to_check == NULL)
	{
		if(optional != NULL)
			free (optional);
		ft_free_all(f);
		exit (1);
	}
}


// typedef struct s_env
// {
// 	char *var_name;
// 	char *value;
// 	struct s_env *next;
// }t_env;

env_line = "USER=hed-dyb";

t_env *ft_create_env(char *env_line, t_free *f)
{
	t_env *node;

	node = malloc(sizeof(t_env));
	ft_protection(node, NULL, f);
	ft_add_t_free(&f, ft_create_t_free(node, f));
	node

	

	
}

ft_create_env_var(t_env **e, char **env, t_free *f)
{
	int	i;

	i = 0;
	while(env[i])
	{
		ft_add_t_env(e, ft_create_t_env(env[i],f));
	}
}

void ft_expander(t_env **e, char **env, t_token **t, t_free *f)
{
	if(*e == NULL)
		ft_create_env_var(e, env, f);
}


//----------------
void ff(void)
{
	system("leaks minishell");
}

int main (int argc, char **argv, char  **env)
{
	t_token *t;
	t_free  *f;
	char *command;
	t_env *e;
	(void)argv;
	// (void)env;//remove this after you create the function
	e = NULL;
	atexit(ff);
	if(argc != 1)
		exit (0);
	while(1)
	{
		f = NULL;
		t = NULL;
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
	// ft_expander(&e, env, &t, f);
		// ft_expander(*t, f, env);
		// ft_print_linked_list(t);
		free(command);

	}
	ft_free_all(f);	
}