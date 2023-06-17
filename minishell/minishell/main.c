/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:51:40 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/06/17 17:21:19 by hed-dyb          ###   ########.fr       */
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
		printf("%d ==> %s    %d\n", i, t->token, t->type);
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

int ft_is_a_white_space(char c)
{
	if(c == ' ' || (c >= 9 && c <= 13))
		return 1;
	return 0;
}

int ft_strlen(char *s)
{
	int i = 0;
	while(s && s[i])
		i++;
	return i;
}

void ft_create_node(t_token **t, char *tok, t_type tp)
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
	node->token[i] = '\0';
	if(*t == NULL)
	{
		node->next = NULL;
		node->previous = NULL;
		*t = node;
		return ;
	}
	else
	{
		while(*t)
		{
			if((*t)->next == NULL)
				break ;
			*t = (*t)->next;
		}
		(*t)->next = node;
		node->previous = *t;
		node->next = NULL;
	}
}
// t_token	*ft_lstnew(char *ptr, t_type type)
// {
// 	t_token *node;

// 	node = malloc(sizeof(t_token));
// 	if (!node)
// 		return (NULL);
// 	node->token = ptr;
// 	node->type = type;
// 	node->next = NULL;
// 	node->previous = NULL;
// 	return (node);
// }
// ft_lstadd_back() put the node in the end of linked list
// ft_lstadd_front() put it in the end 

//white space | >> << < > variable ($example) "" '' else = word
//' '/ | / << / >> / > / <    == bonus no need   && || * ()
// t_token *ft_create_tokens(char *command)
// {
// 	int i;
// 	t_token *t = NULL;

// 	i = 0;
		
// 	while(command[i])
// 	{
// 		if (ft_is_a_white_space(command[i]) == 1)
// 		{
// 			ft_
// 			ft_create_node(&t, " ", _white_space);
// 			while(command[i])
// 			{
// 				if(command[i + 1] == '\0' || ft_is_a_white_space(command[i + 1]) == 0)
// 					break ;
// 				i++;
// 			}		
// 		}
// 		else if (command[i] == '|')
// 			ft_create_node(&t, "|", _pipe);
// 		else if (command[i] == '>' && command[i + 1] == '>')
// 		{
// 			ft_create_node(&t, ">>", _append_output_re);
// 			i++;
// 		}
// 		else if (command[i] == '<' && command[i + 1] == '<')
// 		{
// 			ft_create_node(&t, "<<", _here_document);
// 			i++;
// 		}
// 		else if (command[i] == '>')
// 			ft_create_node(&t, ">", _output_re);
// 		else if (command[i] == '<')
// 			ft_create_node(&t, "<", _input_re);
// 		// printf("%d    ", i);
// 		i++;
// 	}

// 	return t;
// 	// if (token previous == isword() && token next == isword())
// 	// 	skip;
// 	// else
// 	// 	delete;
	
// }

int ft_case_space_or_pipe(t_token **ptr, char *command, int i)
{
	if (ft_is_a_white_space(command[i]) == 1)
	{
		ft_create_node(ptr, " ", _white_space);
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
		ft_create_node(ptr, "|", _pipe);
		return i;
	}
	return i;
}

void ft_create_tokens(t_token *t, char *command)
{
	int i;

	i = 0;
	while(command[i])
	{
		if (ft_is_a_white_space(command[i]) == 1 || command[i] == '|')
			i = ft_case_space_or_pipe(&t, command, i);

		i++;
	}
}


int main (int argc, char **argv)
{
	
	// printf("here ---\n");
	(void)argc;
	(void)argv;
	t_token *t = NULL;
	char *command;
	while(1)
	{
		command = readline("minishell= ");
		if(command == NULL )
			exit (0);
		add_history(command);
		
		ft_create_tokens(t, command);
		ft_print_linked_list(t);
		free(command);
	}
}