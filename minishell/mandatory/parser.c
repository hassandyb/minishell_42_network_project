/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:54:34 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/06/21 14:31:43 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_is_a_redirection(t_type type)
{
	if(type == _append_output_re || type == _here_document || type == _output_re || type == _input_re)
		return 1;
	return 0;
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

int ft_parsing(t_token *t)
{
	if(t->type == _pipe)// pipe in the begining
		return (printf("syntax error\n"), 0);
	while(t)
	{
		if(t->next && t->type == _pipe  && t->next->type == _pipe)// case ||||
			return (printf("syntax error\n"), 0);
		if(t->next && ft_is_a_redirection(t->type) == 1 && t->next->type == _pipe)// redirection then pipe
			return (printf("syntax error\n"), 0);
		if(t->next && t->type == _pipe && ft_is_a_redirection(t->next->type) == 1)// pipe then redirection
			return (printf("syntax error\n"), 0);
		if((t->type == _single_quote || t->type == _double_quote) && ft_check_close(t) == 0)// qoute not closed
			return (printf("syntax error\n"), 0);
		if(t->next == NULL && t->type == _pipe) //pipe in the end
			return (printf("syntax error\n"), 0);
		t = t->next;
	}
	return (1);
}