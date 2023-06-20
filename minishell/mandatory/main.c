/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:51:40 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/06/20 23:33:15 by hed-dyb          ###   ########.fr       */
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
		printf("%d ==> %s  %s!\n", i, t->token, typeNames[t->type]);
		i++;
		t = t->next;
	}
	printf("\n\n");
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



//---------------------------

	// _white_space,  --
	// _pipe,
	// _append_output_re, //>>    --
	// _here_document,//  << --- 
	// _output_re,//  > -- 
	// _input_re,//   < -- 
	// _double_quote,//""
	// _single_quote, //''
	// _word,--
	
// in case of error santax 
//in case of pipe 
// cmd should be start with word variable dq sq redirections=== !|  or ||| many pipes  done
// redirections next should be word variable dq sq         done
// pipe next should be variable dq sq word                    done
// single qoute and double should be closed done


// "abcd"\0
//        len;


	   
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
	//ask what can not bt be in the end
}


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
	if(argc != 1)
		exit (0);
	while(1)
	{
		f = NULL;
		t = NULL;
		command = readline("minishell= ");
		if(command == NULL)
			exit (0);
		add_history(command);
		ft_create_tokens(&t, command, &f);
		if(ft_parsing(t) == 0)
		{
			free(command);
			ft_free_all(f);
			continue ;
		}
		// ft_print_linked_list(t);
		free(command);

	}
	ft_free_all(f);	
}