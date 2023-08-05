/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:54:34 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/07/20 18:00:07 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../exec.h"
int ft_is_wrd_qot(t_token *temp)
{
	if(temp == NULL)
		return (0);
	if(temp->type == _word)
		return (1);
	if(temp->type == _double_quote)
		return (1);
	if(temp->type == _single_quote)
		return (1);
	return (0);
}

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

int ft_check_file(t_token *t)// here i checl the i have (redirection </>..) then space then word/quote(for file fd or delimeter)
{	
	if(ft_is_wrd_qot(t->next) == 1)
		return (1);
	if(t->next->type == _white_space && ft_is_wrd_qot(t->next->next) == 1)
		return (1);
	return (0);

}


void ft_error(char *msg)
{
	int i;

	i = -1;
	while(msg[++i])
		write(STDERR_FILENO, &msg[i], 1);
	g_exit_status = 2;
}
int ft_parsing(t_token *t)
{
	if(t && t->type == _pipe)// pipe in the begining
		return (ft_error(" syntax error near unexpected token `|'\n"), 0);
	if(t && ft_is_a_redirection(t) && t->next == NULL)
		return (ft_error(" syntax error near unexpected token `newline'\n"), 0);
	while(t)
	{
		if(ft_strcmp(t->token, "<<<") != 0)
			return (ft_error(" syntax error near unexpected token `newline'\n"), 0);
		if(ft_strcmp(t->token, ">>>") != 0)
			return (ft_error(" syntax error near unexpected token `>'\n"), 0);
		// if(ft_is_q)



		if(t->next && t->type == _pipe  && t->next->type == _pipe)// case pipe then pipe.
			return (ft_error(" syntax error\n"), 0);
		if(t->next && ft_is_a_redirection(t) == 1 && (t->next->type == _pipe || ft_is_a_redirection(t->next) == 1))// redirection then pipe
			return (ft_error(" syntax error\n"), 0);
		if((t->type == _single_quote || t->type == _double_quote) && ft_check_close(t) == 0)// qoute not closed
			return (ft_error(" syntax error\n"), 0);
		if(t->next == NULL && t->type == _pipe) //pipe in the end
			return (ft_error(" syntax error\n"), 0);
		if(ft_is_a_redirection(t) == 1 && ft_check_file(t) == 0)//
			return (ft_error(" syntax error\n"), 0);
		t = t->next;
	}
	return (1);
}