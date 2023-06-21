/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 14:13:28 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/06/21 14:38:33 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token *ft_create_node(char *tok, int type_, t_free **f, char *command)
{
	int i;
	t_token *node;

		
	i = 0;
	node = malloc(sizeof(t_token));
	node->token = malloc((ft_strlen(tok) + 1) * sizeof(char));
	if(node == NULL || node->token == NULL)
	{
		free (command);
		ft_free_all(*f);
		exit(1);
	}
	ft_add_t_free(f, ft_create_t_free(node, *f));
	node->type = type_;
	while(tok && tok[i])
	{
		node->token[i] = tok[i];
		i++;
	}
	node->token[i] = '\0';
	node->next = NULL;
	node->previous = NULL;
	return node;
}

void ft_add_back(t_token **t, t_token *node)
{
	t_token *temp;
	
	temp = *t;
	if(*t == NULL)
	{
		*t = node;
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
		node->previous = temp;
	}
}

int ft_end_of_word(char *command, int i)
{
	while(command[i])
	{
		if(command[i + 1] == '\0' || command[i + 1] == '|' || command[i + 1] == '<'
			|| command[i + 1] == '>' || ft_is_a_white_space(command[i + 1]) == 1)
				break ;
		i++;
	}
	return i;
}

int ft_char_indice(char *command, int i, char c)
{
	i++;
	while(command[i])
	{
		if(command[i] == c)
			break;
		i++;
	}
	return i;
}

int ft_is_a_word(t_token **t, char *command, int i, t_free **f)
{
	t_token *node;
	char *tok;
	int j;
	int start ;

	start = i;
	j = 0;
	i = ft_end_of_word(command, i);
	tok = malloc((i - start + 2) * sizeof(char));
	ft_protection(tok, command, *f);
	ft_add_t_free(f, ft_create_t_free(tok, *f));
	while(command[start])
	{
		tok[j] = command[start];
		if(start == i)
			break ;
		j++;
		start++;
	}

	tok[j + 1] = '\0';
	node = ft_create_node(tok, _word, f, command);
	ft_add_back(t, node);
	return i;
}

