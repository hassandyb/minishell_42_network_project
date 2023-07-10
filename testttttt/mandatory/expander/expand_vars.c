/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_vars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:24:49 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/07/08 17:26:28 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_valid_var(char *tok)
{
	int dollar;

	dollar = ft_find_char(tok, '$');
	if(dollar == -1)
		return (0);
	if(tok[dollar + 1] == '_' || ft_isalpha(tok[dollar + 1]) == 1)
		return (1);
	return (0);
}

void ft_begin_and_end(char *token, int *begin, int *end)
{
	int i;

	i = 0;
	while(token && token[i])
	{
		if(token[i] == '$')
		{
			*begin = i;
			i++;
			break ;
		}
		i++;
	}
	while(token && token[i] && (ft_islnum(token[i]) == 1 || token[i] == '_'))
		i++;
	*end = i - 1;
}

char *ft_get_var_value(t_env *e, char *var, t_free *f)
{
	int i;
	
	while(e)
	{
		i = 0;
		while((e->var_name[i] && var[i]) && e->var_name[i] == var[i] )
			i++;
		if(ft_strlen(var) == i &&  ft_strlen(e->var_name) == i)
			return(e->value);
		e = e->next;
	}
	return(ft_strdup("", f));
}

void ft_replace(t_token *node,t_env *e, t_free *f)
{
	int begin = 0;
	int end = 0;


	char *var_value;
	char *befor;
	char *after;
	
	while (ft_find_char(node->token, '$') >= 0 && ft_valid_var(node->token) == 1)//ft(node->token[begin + 1])
	{
		
		ft_begin_and_end(node->token, &begin, &end);
		befor = ft_substr(node->token, 0, begin, f);
		var_value = ft_get_var_value(e, ft_substr(node->token, begin + 1, end - begin, f), f);
		befor = ft_strjoin(befor, var_value, f);
		after = ft_substr(node->token, end + 1, ft_strlen(node->token) - end - 1, f);
		node->token = ft_strjoin(befor, after, f);
	}
}

void ft_expand_var(t_token *t, t_env *e, t_free *f)
{
	int i;
	t_token *temp;

	temp = t;
	i = 0;
	while(temp)
	{
		if((temp->type == _word || temp->type == _double_quote ))
		{
			if(i == 0)
				ft_replace(temp, e, f);
				
			else if(i == 1 && temp->previous->type != _here_document)
				ft_replace(temp, e, f);	
				
			else if(i >= 2 && (temp->previous->type != _here_document && temp->previous->previous->type != _here_document))
				ft_replace(temp, e, f);
		}
		temp = temp->next;
		i++;
	}
}

