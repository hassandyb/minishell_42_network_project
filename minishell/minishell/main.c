/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:51:40 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/06/18 20:21:11 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_print_linked_list(t_token *t)
{
	if(t == NULL)
		printf("NULL\n");
		int i = 0;
	while(t)
	{
		printf("%d ==> %s    %s\n", i, t->token, typeNames[t->type]);
		i++;
		t = t->next;
	}
}

// tokenizing
// |||

// parcer   chiking syntax

// filer new prompt    -          success expander 
// create is a white space ...
//cat file.txt |  				 grep "example 1"\0

//white space | >> << < > variable ($example) "" '' else = word
//' '/ | / << / >> / > / <    == bonus no need   && || * ()



t_token *ft_create_node(t_token *ptr, char *tok, int tp)
{
	int i;
	t_token *node;

	i = 0;
	node = malloc(sizeof(t_token));
	// protection
	node->type = tp;
	node->token = malloc((ft_strlen(tok) + 1) * sizeof(char));
	//protection
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

void ft_add_back(t_token **ptr, t_token *node)
{
	t_token *temp;
	
	temp = *ptr;
	if(*ptr == NULL)
	{
		*ptr = node;
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

int ft_case_space_or_pipe(t_token **ptr, char *command, int i)
{
	t_token *node;

	node = NULL;
	if (ft_is_a_white_space(command[i]) == 1)
	{
		node = ft_create_node(*ptr, " ", _white_space);
		ft_add_back(ptr, node);
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
		node = ft_create_node(*ptr, "|", _pipe);
		ft_add_back(ptr, node);
		return i;
	}
	return i;
}

int ft_case_redirections(t_token **ptr, char *command, int i)
{
	t_token *node;

	node = NULL;
	if(command[i] == '>' && command[i + 1] == '>')
	{
		node = ft_create_node(*ptr, ">>", _append_output_re);
		i++;;
	}
	else if(command[i] == '<' && command[i + 1] == '<')
	{
		node = ft_create_node(*ptr, "<<", _here_document);
		i++;;
	}
	else if(command[i] == '>')
		node = ft_create_node(*ptr, ">", _output_re);
	else if(command[i] == '<')
		node = ft_create_node(*ptr, "<", _input_re);
	ft_add_back(ptr, node);
	return i;

}

void ft_create_tokens(t_token **ptr, char *command)
{
	int i;

	i = 0;
	while(command && command[i])
	{
		// printf("%d----\n", i);
		if (ft_is_a_white_space(command[i]) == 1 || command[i] == '|')
			i = ft_case_space_or_pipe(ptr, command, i);
		else if(command[i] == '<' || command[i] == '>')
			i = ft_case_redirections(ptr, command, i);

		i++;
	}
}
//---------------------------



//----------------
// void ff(void)
// {
// 	system("leaks minishell");
// }

int main (int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_token *t;
	t_free  *f;
	char *command;
	// atexit(ff);
	while(1)
	{
		t = NULL;
		command = readline("minishell= ");
		if(command == NULL )
			exit (0);
		add_history(command);
		ft_create_tokens(&t, command, &f);
		ft_print_linked_list(t);
		free(command);
	}




	

	
}