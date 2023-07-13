/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:51:40 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/07/13 15:23:44 by hed-dyb          ###   ########.fr       */
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
void ft_print_t_cmd_linked_list(t_cmd *cmd)
{
	if(cmd == NULL)
		printf("NULL\n");
	while(cmd)
	{
		int j = 0;
		while(cmd->comand[j])
		{
			printf("command[%d] %s\n",j, cmd->comand[j]);
			j++;
		}
		printf("\n");
		cmd = cmd->next;
	}
	printf("\n\n");
}

void ft_print_t_red(t_red *r)
{
	if(r == NULL)
	{
		printf("NULL\n");
		return;
	}
	while(r)
	{
		printf("%s--%s    ", typeNames[r->type], r->file);
		r = r->next;
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

			// typedef struct s_red 
			// {
			// 	t_type type;
			// 	char *file;
			// 	struct s_red *next;
			// }t_red;

			// typedef struct s_cmd
			// {
			// 	char **comand;
			// 	t_red *red;
			// 	struct s_cmd *next;//,_cmd *next;
			// }t_cmd;
//____________________________________________________________________
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

t_token *ft_next_part(t_token *temp)
{
	while(temp)
	{
		if(temp->type == _pipe)
		{
			temp = temp->next;
			break;
		}
		temp = temp->next;
	}
	return (temp);
}

void ft_protect(void *ptr, t_free *f)
{
	if(ptr == NULL)
	{
		ft_free_all(f);
		exit (1);
	}
}

void ft_add_back_t_red(t_red **r, t_red *node)
{
	t_red *temp;
	
	temp = *r;
	if(*r == NULL)
		*r = node;
	else
	{
		while(temp)
		{
			if(temp->next == NULL)
				break;
			temp = temp->next;
		}
		temp->next = node;
	}
	
}

t_red *ft_create_t_red(t_token *temp, t_free *f)
{
	t_red *r;
	t_red *node;

	r = NULL;
	while(temp && temp->type != _pipe)
	{
		if(ft_is_a_redirection(temp) == 1)
		{
			node = malloc(sizeof(t_red));
			ft_protect(node, f);
			ft_add_t_free(&f, ft_create_t_free(node, f));
			node->type = temp->type;
			node->file = ft_strdup(temp->next->token, f);
			node->next = NULL;
			ft_add_back_t_red(&r, node);
			temp = temp->next;
		}
		temp = temp->next;
	}
	return r;
}

void ft_add_back_t_cmd(t_cmd *cmd, char **com, t_red *r, t_free *f)
{
	t_cmd *node;

	node = malloc(sizeof(t_cmd));
	ft_protect(node, f);
	ft_add_t_free(&f, ft_create_t_free(node, f));
	node->comand = com;
	node->
	
}
void ft_comand_info(t_cmd **cmd, t_token **t, t_free *f)
{

	t_token *temp;
	char **comand;
	t_red *red;
	
	temp = *t;
	*cmd = NULL;
	while(temp)
	{
		comand = ft_comand_with_args(temp, f);
		red = ft_create_t_red(temp, f);
		ft_add_back_t_cmd(cmd, comand, red,f);
		// ft_print_t_red(red);


		
		// node = malloc(sizeof(t_cmd))
		// ft_create_t_cmd()
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
		// ft_print_t_cmd_linked_list(cmd);
		ft_comand_info(&cmd, &t, f);
	}
	ft_free_all(f);	
}