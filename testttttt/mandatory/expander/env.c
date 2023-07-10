/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:20:23 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/07/08 17:28:12 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

void ft_expander(t_token **t, t_env **e, char **env, t_free *f)
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
	ft_expand_var(*t, *e, f);
	ft_split_spaces(t, f);
	ft_concatenate(t, f);
}
