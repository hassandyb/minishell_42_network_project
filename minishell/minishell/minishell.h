/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:52:06 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/06/16 13:10:16 by hed-dyb          ###   ########.fr       */
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
	word,
	white_space,
	double_quote,//""
	single_quote, //''
	variable,
	pipe,
}	t_type;


typedef struct s_token
{
	char *data;
	t_type type;// will take a vaule from the t_type evry time
	struct s_token *next;
	struct s_token *previous;
	
}t_token;


// typedef enum e_type
// {
// 	type1,
// 	type2,
// 	type
	
// } t_type;

// typedef enum e_day 
// {
// 	monday, 
// 	tuesday , 
// 	wednsday, 
// 	thursday , 
// 	friday, 
// 	saturday, 
// 	sunday
// }t_day;

#endif