/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:51:40 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/06/20 15:40:59 by hed-dyb          ###   ########.fr       */
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

// in case of error santax 
//in case of pipe 
// cmd should be start with word variable dq sq redirections=== !|  or ||| many pipes 
// redirections next should be word variable dq sq  
// pipe next should be variable dq sq word
// single qoute and double should be closed

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
		ft_unnecessary_spaces(&t);
		// if(ft_parcer () == 0)
		// {
		// 	//free
		// 	//contunie
			
		// }
		ft_print_linked_list(t);
		free(command);

	}
	ft_free_all(f);	
}