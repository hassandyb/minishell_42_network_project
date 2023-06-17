/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:51:40 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/06/17 13:03:42 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

tokenizing
|||

parcer   chiking syntax

filer new prompt    -          success expander 
// create is a white space ...
//cat file.txt |  				 grep "example 1"\0

int ft_strlen(char *s)
{
	int i = 0;
	while(s && s[i])
		i++;
	return i;
}

void ft_create_node(t_token *t, char *tok, t_type tp)
{
	int i;
	
	i = 0;
	t_token *node = malloc(sizeof(t_token));
	//protection
	node->type = tp;
	node->token = malloc((ft_strlen(tok) + 1 )* sizeof(char));
	//protection
	while(tok[i])
	{
		node->token[i] = tok[i];
		i++;
	}
	tok[i] = '\0';
	if(t == NULL)
	{
		node->next = NULL;
		node->previous = NULL;
		return node;
	}
	else
	{
		while(t)
		{
			if(t->next == NULL)
				break ;
			t = t->next;
		}
		t->next = node;
		node->previous = t;
		node->next = NULL;
	}
}



//white space | >> << < > variable ($example) "" '' else = word
//' '/ | / << / >> / > / <    == bonus no need   && || * ()
t_token *ft_create_tokens(char *command)
{
	int i;
	t_token *t;

	i = 0;
	t = NULL;
	while(command[i])
	{
		if (ft_is_a_white_space(command[i]) == 1)
		{
			ft_create_node(t, " ", _white_space);
			while(command[i])
			{
				if(command[i + 1] == '\0' || ft_is_a_white_space(command[i + 1]) == 0)
					break ;
				i++;
			}
					
		}
		else if (command[i] == '|')
			ft_create_node(t, "|", _pipe);
		else if (command[i] == '>' && command[i + 1] == '>')
		{
			ft_create_node(t, ">>", _append_output_re);
			i++;
		}
		else if (command[i] == '<' && command[i + 1] == '<')
		{
			ft_create_node(t, "<<", _here_document);
			i++;
		}
		else if (command[i] == '>')
			ft_create_node(t, ">", _output_re);
		else if (command[i] == '<')
			ft_create_node(t, "<", _input_re);
		// else if (command[i] == '>')
		// {
		// 	if (command[i+1] == '>')
		// 	{
		// 		ft_create_node(t, ">>", append_output_re);
		// 		i++;
		// 	}
		// 	else
		// 		ft_create_node(t, ">", append_output_re);
		// 		//append_output_re  >>
		// }
		i++;
	}
	return NULL;
	// if (token previous == isword() && token next == isword())
	// 	skip;
	// else
	// 	delete;
	
}
int main (int argc, char **argv)
{
	
	(void)argc;
	(void)argv;
	t_token *t;
	char *command;
	while(1)
	{
		command = readline("minishell>> ");
		if(command == NULL )
			exit (0);
		add_history(command);
		t = ft_create_tokens(command);
		free(command);
	}
}