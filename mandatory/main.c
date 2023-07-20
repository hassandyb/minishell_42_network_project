/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:51:40 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/07/20 17:00:51 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "exec.h"
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

// void ft_printf_double_ptr(char **str)
// {
// 	if(str == NULL)
// 	{
// 		printf("NULL\n");
// 		return ;
// 	}
// 	int i = 0;
// 	while(str[i])
// 	{
// 		printf("%s  - ", str[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

void ft_print_t_red(t_red *r)
{
	if(r == NULL)
	{
		printf("redirection NULL\n");
		return;
	}
	int i = 0;
	while(r)
	{
		printf("redirection[%d]  %s   %s\n", i, typeNames[r->type], r->file);
		r = r->next;
		i++;
	}
	printf("\n");
}

void ft_print_t_cmd_linked_list(t_cmd *cmd)
{
	if(cmd == NULL)
		printf("NULL\n");
	while(cmd)
	{
		int j = 0;
		if(cmd->comand == NULL)
			printf(" command NULL\n");
		else
		{
			while(cmd->comand[j])
			{
				printf("command[%d]  %s\n",j, cmd->comand[j]);
				j++;
			}
		}
		ft_print_t_red(cmd->red);
		printf("\n");
		cmd = cmd->next;
	}
	printf("\n\n");
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
	// t_cmd *cmds;
	// cmds = malloc(sizeof(t_cmd));
	// cmds->comand = malloc(sizeof(char *) * 3);
	// cmds->comand[0] = ft_strdup("ls", NULL);
	// cmds->comand[1] = ft_strdup("-l", NULL);
	// cmds->comand[2] = NULL;
	// cmds->next = malloc(sizeof(t_cmd));
	// cmds->next->comand = malloc(sizeof(char *) * 3);
	// cmds->next->comand[0] = ft_strdup("cat", NULL);
	// cmds->next->comand[1] = ft_strdup("main.c", NULL);
	// cmds->next->comand[2] = NULL;
	// cmds->next->next = malloc(sizeof(t_cmd));
	// cmds->next->next->comand = malloc(sizeof(char *) * 3);
	// cmds->next->next->comand[0] = ft_strdup("echo", NULL);
	// cmds->next->next->comand[1] = ft_strdup("hello world", NULL);
	// cmds->next->next->comand[2] = NULL;
	// cmds->next->next->next = NULL;
	// ft_print_t_cmd_linked_list(cmds);
	// exec(cmds, e);
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
		ft_comand_info(&cmd, &t, f);
		// ft_print_t_cmd_linked_list(cmd);
	}
	ft_free_all(f);	
}