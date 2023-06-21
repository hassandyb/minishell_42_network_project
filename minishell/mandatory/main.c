/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:51:40 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/06/21 13:03:30 by hed-dyb          ###   ########.fr       */
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



t_env *ft_create_env(char *env_line)
{
	// t_env
}

ft_create_env_var(t_env **e, char **env, t_free *f)
{
	int	i;

	i = 0;
	while(env[i])
	{
		ft_add_t_env(e, ft_create_t_env( env[i],f));
	}
}

void ft_expander(t_env **e, char **env, t_token **t, t_free *f)
{
	if(*e == NULL)
		ft_create_env_var(e, env, f);
}


//----------------
// void ff(void)
// {
// 	system("leaks minishell");
// }

int main (int argc, char **argv, char  **env)
{
	t_token *t;
	t_free  *f;
	char *command;
	t_env *e;

	e = NULL;
	// atexit(ff);
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
			free(command);
			ft_free_all(f);
			continue ;
		}
	ft_expander(&e, env, &t, f);
		// ft_expander(*t, f, env);
		// ft_print_linked_list(t);
		free(command);

	}
	ft_free_all(f);	
}