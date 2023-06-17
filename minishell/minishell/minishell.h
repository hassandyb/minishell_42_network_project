/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:52:06 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/06/17 14:54:15 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef enum e_type
{
	_white_space,
	_pipe,
	_append_output_re, //>>
	_here_document,//  <<
	_output_re,//  >
	_input_re,//   <
	_word,
	_double_quote,//""
	_single_quote, //''
	_variable,
}	t_type;


typedef struct s_token
{
	char	*token;
	t_type	type;// will take a vaule from the t_type evry time
	struct	s_token *next;
	struct	s_token *previous;
	
}t_token;


#endif