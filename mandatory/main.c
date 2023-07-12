/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:51:40 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/07/12 17:53:42 by hed-dyb          ###   ########.fr       */
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

void ft_printf_double_ptr(char **str)
{
	if(str == NULL)
	{
		printf("NULL\n");
		return ;
	}
	int i = 0;
	while(str[i])
	{
		printf("%s  - ", str[i]);
		i++;
	}
	printf("\n");
}
// tokenizer
// parcer
// expander
// conncater
// execution
//  ft_find_cha
//  0 = does not exist
//  1 = does exist 

// 

// typedef struct s_cmd
// {
// 	char **comand;
// 	int ofd;
// 	int ifd;
// 	// struct s;//,_cmd *next;
// }t_cmd;

int ft_count(t_token *temp)
{
	int count;

	count = 0;
	while(temp && temp->type != _pipe)
	{
		if(ft_is_a_redirection(temp) == 1)
			temp = temp->next;
		else
			count++;
		temp = temp->next;
	}
	return (count);
}

char **ft_comand_with_args(t_token *temp, t_free *f)
{
	int count;
	char **comand;
	count = ft_count(temp);

	
	if (count == 0)
		return NULL;
	comand = malloc((count + 1) * sizeof(char *));
	ft_protection_2(comand, NULL, f);
	ft_add_t_free(&f, ft_create_t_free(comand, f));
	count = 0;
	while(temp && temp->type != _pipe)
	{
		if(ft_is_a_redirection(temp) == 1)
			temp = temp->next;
		else
		{
			comand[count] = ft_strdup(temp->token, f);
			count++;
		}
		temp = temp->next;
		
	}
	comand[count] = NULL;
	return (comand);
}

void ft_comand_info(t_cmd **cmd, t_token **t, t_free *f)
{
	t_token *temp;
	char **comand;
	// int fd_out;
	// int fd_in;
	(void)cmd;//remove it later
	temp = *t;
	while(temp)
	{
		comand = ft_comand_with_args(temp, f);
		
		// ft_fd_out_in(&fd_in, &fd_out, temp, f);
		// ft_add_t_cmd(&cmd, ft_create_t_cmd(fd_in, fd_out, comand, f));
		temp = ft_next_part(temp);
	}
}

int main (int argc, char **argv, char  **env)
{
	t_token *t;
	t_free  *f;
	t_cmd *cmd;
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
		cmd = NULL;
		command = readline("minishell= ");
		if(command == NULL)
			exit (0);
		add_history(command);
		ft_create_tokens(&t, command, &f);
		if(command[0] == '\0' || ft_parsing(t) == 0)
		{
			ft_free_all(f);
			continue ;
		}
		free(command);
		ft_expander(&t, &e, env, f);
		// ft_print_t_token_linked_list(t);
		ft_comand_info(&cmd, &t, f);
	}
	ft_free_all(f);	
}