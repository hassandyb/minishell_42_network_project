/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:51:40 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/06/20 12:48:51 by hed-dyb          ###   ########.fr       */
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

// tokenizer
// parcer
// expander
// conncater
// execution


// | < > space \0
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

void ft_create_tokens(t_token **t, char *command, t_free **f)
{
	int i;

	i = 0;
	while(command && command[i])
	{
		if(command[0] == '\0')
		{
			printf("empty comand\n");
			//do something
		}
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
		ft_unnecessary_spaces(&t);
		ft_print_linked_list(t);
		free(command);

	}




	

	
}