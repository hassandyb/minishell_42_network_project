/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:22:13 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/07/20 17:02:47 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


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

t_cmd *ft_create_t_cmd(char **com, t_red *r, t_free *f)
{
	t_cmd *node;
	
	node = malloc(sizeof(t_cmd));
	ft_protect(node, f);
	ft_add_t_free(&f, ft_create_t_free(node, f));
	node->comand = com;
	node->red = r;
	node->next = NULL;
	return (node);
}

void ft_add_back_t_cmd(t_cmd **cmd, t_cmd *node)
{
	t_cmd *temp;
	
	temp = *cmd;
	if(*cmd == NULL)
	{
		*cmd = node;
		return;
	}
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

void ft_comand_info(t_cmd **cmd, t_token **t, t_free *f)
{

	t_token *temp;
	char **comand;
	t_red *red;
	t_cmd *node;
	
	temp = *t;
	*cmd = NULL;
	while(temp)
	{
		comand = ft_comand_with_args(temp, f);
		red = ft_create_t_red(temp, f);
		node = ft_create_t_cmd(comand, red, f);
		ft_add_back_t_cmd(cmd, node);
		temp = ft_next_part(temp);
	}
	ft_in_out_fd();
}