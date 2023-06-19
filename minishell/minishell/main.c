/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:51:40 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/06/19 18:33:12 by hed-dyb          ###   ########.fr       */
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

// char *ft_substr(char *str, int indice, int len)
// {
// 	char *result;
	
// 	if(str == NULL || 
// 		return NULL;
// 	result = malloc((len + 1) * sizeof(char));
	
// }

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

int ft_case_space_or_pipe(t_token **t, char *command, int i, t_free **f)
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

int ft_case_redirections(t_token **t, char *command, int i, t_free **f)
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

// $HOME
// 45678

int ft_end_of_variable(char *command, int i)
{
	while(command[i])
	{
		if(command[i + 1] == '_' || (command[i + 1] >= '0' && command[i + 1] 
			<= '9') || (command[i + 1] >= 'a' && command[i + 1] <= 'z') 
			|| (command[i + 1] >= 'A' && command[i + 1] <= 'Z'))
				i++;
		else
			break ;
	}
	return i;
}

// $home
// 34567
int ft_case_variable(t_token **t, char *command, int i, t_free **f)
{
	int start;
	int j;
	char *tok;
	t_token *node;
	
	j = 0;
	start = i;
	i = ft_end_of_variable(command , i);
	tok = malloc((i - start + 2) * sizeof(char));
	if(tok == NULL)
	{
		free (command);
		ft_free_all(*f);
		exit (1);
	}
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
	node = ft_create_node(tok, _variable, f, command);
	ft_add_back(t, node);
	return i;
}

void ft_create_tokens(t_token **t, char *command, t_free **f)
{
	int i;

	i = 0;
	while(command && command[i])
	{
		// printf("%d----\n", i);
		if (ft_is_a_white_space(command[i]) == 1 || command[i] == '|')
			i = ft_case_space_or_pipe(t, command, i, f);
		else if(command[i] == '<' || command[i] == '>')
			i = ft_case_redirections(t, command, i, f);
		else if(command[i] == '$')// a variable cannot start with a number.
			i = ft_case_variable(t, command, i, f);
		// else if(ft_case)
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
	t_token *t;
	t_free  *f;
	char *command;
	(void)argv;
	// atexit(ff);
	f = NULL;
	while(1)
	{
		t = NULL;
		command = readline("minishell= ");
		if(command == NULL || argc != 1)
			exit (0);
		add_history(command);
		ft_create_tokens(&t, command, &f);
		ft_print_linked_list(t);
		free(command);

	}




	

	
}