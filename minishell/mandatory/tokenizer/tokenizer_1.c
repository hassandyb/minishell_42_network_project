/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:49:42 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/06/22 11:52:57 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_space_or_pipe(t_token **t, char *command, int i, t_free **f)
{
	t_token *node;

	node = NULL;
	if (ft_is_a_white_space(command[i]) == 1)
	{
		node = ft_create_node(" ", _white_space, f, command);
		ft_add_back(t, node);
		while(command[i])
		{
			if(command[i + 1] == '\0' || ft_is_a_white_space(command[i + 1]) == 0)
				break ;
			i++;
		}
		return i;	
	}
	if (command[i] == '|')
	{
		node = ft_create_node("|", _pipe, f, command);
		ft_add_back(t, node);
		return i;
	}
	return i;
}

int ft_redirections(t_token **t, char *command, int i, t_free **f)
{
	t_token *node;

	node = NULL;
	if(command[i] == '>' && command[i + 1] == '>')
	{
		node = ft_create_node(">>", _append_output_re, f, command);
		i++;;
	}
	else if(command[i] == '<' && command[i + 1] == '<')
	{
		node = ft_create_node("<<", _here_document, f, command);
		i++;;
	}
	else if(command[i] == '>')
		node = ft_create_node(">", _output_re, f, command);
	else if(command[i] == '<')
		node = ft_create_node("<", _input_re, f, command);
	ft_add_back(t, node);
	return i;

}

int ft_double_qoute(t_token **t, char *command, int i, t_free **f)
{
	int start;
	char *tok;
	int j;
	t_token *node;

	j = 0;
	start = i;
	i = ft_char_indice(command, i, '"');
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
	node = ft_create_node(tok, _double_quote, f, command);
	ft_add_back(t, node);
	return i ;	
}

int ft_single_quote(t_token **t,char *command, int i, t_free **f)
{
	t_token *node;
	int start;
	char *tok;
	int j;

	j = 0;
	start = i;
	i = ft_char_indice(command, i, '\'');
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
	node = ft_create_node(tok, _single_quote, f, command);
	ft_add_back(t, node);
	return i;
}

void ft_create_tokens(t_token **t, char *command, t_free **f)
{
	int i;

	i = 0;
	while(command[i] && ft_is_a_white_space(command[i]) == 1 )
		i++;
	while(command && command[i])
	{
		if (ft_is_a_white_space(command[i]) == 1 || command[i] == '|')
			i = ft_space_or_pipe(t, command, i, f);
		else if(command[i] == '<' || command[i] == '>')
			i = ft_redirections(t, command, i, f);
		else if(command[i] == '\"')
			i = ft_double_qoute(t, command, i, f);
		else if(command[i] == '\'')
			i = ft_single_quote(t, command, i, f);
		else
			i = ft_is_a_word(t, command, i, f);
		i++;
	}
	ft_unnecessary_spaces(t);
	free(command);
	command = NULL;
}
