/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:51:40 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/07/07 23:51:18 by hed-dyb          ###   ########.fr       */
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
//  ft_find_cha
//  0 = does not exist
//  1 = does exist 

//  creating env var


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
//    expanding vars   ---------------------------------

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

char *ft_strdup(char *str, t_free *f)
{
	int i;
	char *copy;
	
	if(str == NULL)
		return (NULL);
	copy = malloc((ft_strlen(str) + 1) * sizeof(char));
	ft_protection(copy, NULL, f);
	ft_add_t_free(&f, ft_create_t_free(copy, f));
	i = 0;
	while(str[i])
	{
		copy[i] = str[i];	
		i++;
	}
	copy[i] = '\0';
	return (copy);
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
//  spliting spaces  with spaces caused by vars values  -----------

//split spaces   ___________________________________

void ft_add_new_to_t(t_token **t, t_token *temp, t_token *new)
{
	t_token *prv;
	t_token *nxt;

	prv = temp->previous;
	nxt = temp->next;
	if(prv != NULL)
		prv->next = new;
	if(new != NULL)
		new->previous = prv;
	if(temp == *t)
		*t = new;
	while(new)
	{
		if(new->next == NULL)
			break;
		new = new->next;
	}
	if(new != NULL)
		new->next = nxt;
	if(nxt != NULL)
		nxt->previous = new;
}
	
void ft_split_spaces(t_token **t, t_free *f)
{
	t_token *temp;
	char **result = NULL;
	temp = *t;
	int i;
	t_token *new;

	new = NULL;
	while(temp)
	{
		i = 0;
		if(temp->type == _word && ft_find_char(temp->token, ' ') > 0)
		{
			result = ft_split(temp->token, ' ', f);

			while(result[i] != NULL)
			{
				ft_add_back(&new, ft_create_node(result[i], _word, &f, NULL));
				if(result[i + 1] != NULL)
				ft_add_back(&new, ft_create_node(" ", _white_space, &f, NULL));
				i++;
			}

			ft_add_new_to_t(t, temp, new);
		}
		temp = temp->next;
	}
}


//conactinating ______________________

// int ft_wrd_qot(t_token *node)
// {
	// if(node->type == _word)
	// 	return (1);
	// if(node->type == _single_quote)
	// 	return (1);
	// if(node->type == _word)
	// 	return (1);
	
// }


// void ft_concatenate(t_token **t)
// {
// 	while(ft_is_wrd_qot(*t) == 1 && ft_is_wrd_qot((*t)->next) == 1)
// 	{
		
// 	}
	
// 	while()
// }





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
	// ft_concatenate(t);
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
		ft_print_t_token_linked_list(t);
		ft_expander(&t, &e, env, f);
		ft_print_t_token_linked_list(t);

	}
	ft_free_all(f);	
}