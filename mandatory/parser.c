/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:54:34 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/07/13 13:12:29 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_is_a_redirection(t_token *node)
{
	if(node->type == _output_re)
		return (1);
	else if(node->type == _input_re)
		return (1);
	else if(node->type == _append_output_re)
		return (1);
	else if(node->type == _here_document)
		return (1);
	else
		return (0);
}

int ft_check_close(t_token *t)
{
	int len;
	
	len = ft_strlen(t->token);
	if(t->token[0] == '\'' && t->token[len - 1] == '\'')
		return (1);
	if(t->token[0] == '\"' && t->token[len - 1] == '\"')
		return (1);
	return (0);
}

int ft_unclosed_quote(char *tok)
{
	int i;
	int doubl;
	int singl;
	
	i = 0;
	doubl = 0;
	singl = 0;
	while(tok[i])
	{
		if(tok[i] == '\"')
			doubl++;
		if(tok[i] == '\'')
			singl++;
		i++;
	}
	if(doubl % 2 == 0 && singl % 2 == 0)
		return 0;
	return 1;
	
	
}

int ft_check_file(t_token *t)// here i checl the i have (redirection </>..) then space then word/quote(for file fd or delimeter)
{
	if(t->next == NULL)
		return (0);
	if(t->next->type != _white_space)
		return (0);
	if(t->next->next == NULL)
		return 0;
	if(ft_is_wrd_qot(t->next->next) == 0)
		return (0);
	return (1);
}

int ft_parsing(t_token *t)
{
	if(t->type == _pipe)// pipe in the begining
		return (printf("syntax error\n"), 0);
	while(t)
	{
		if(t->next && t->type == _pipe  && t->next->type == _pipe)// case ||||
			return (printf("syntax error\n"), 0);
		if(t->next && ft_is_a_redirection(t) == 1 && (t->next->type == _pipe || ft_is_a_redirection(t->next) == 1))// redirection then pipe
			return (printf("syntax error\n"), 0);
		if((t->type == _single_quote || t->type == _double_quote) && ft_check_close(t) == 0)// qoute not closed
			return (printf("syntax error\n"), 0);
		if(t->next == NULL && t->type == _pipe) //pipe in the end
			return (printf("syntax error\n"), 0);
		if(t->type && ft_unclosed_quote(t->token) == 1)
			return (printf("syntax error\n"), 0);
		if(ft_is_a_redirection(t) == 1 && ft_check_file(t) == 0)// in case you have redirection folloed by nothing or follo
			return (printf("syntax error\n"), 0);
		
		
		t = t->next;
	}
	return (1);
}