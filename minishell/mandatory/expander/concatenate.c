/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concatenate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:31:35 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/07/08 17:34:07 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"





int ft_is_wrd_qot(t_token *node)
{
	if(node == NULL)
		return (0);
	if(node->type == _word)
		return (1);
	if(node->type == _single_quote)
		return (1);
	if(node->type == _double_quote)
		return (1);
	return (0);
}

char *ft_join_token(t_token *node1, t_token *node2, t_free *f)// i did bot use strjoin casue in case of "" or '' i should remove them.
{
	char *tok1;
	char *tok2;
	if(node1->type == _double_quote || node1->type == _single_quote)
		tok1 = ft_substr(node1->token, 1, ft_strlen(node1->token) - 2, f);
	else
		tok1 = node1->token;
	if(node2->type == _double_quote || node2->type == _single_quote)
		tok2 = ft_substr(node2->token, 1 , ft_strlen(node2->token) - 2, f);
	else
		tok2 = node2->token;
	return (ft_strjoin(tok1, tok2, f));
}

void ft_if_its_inside(t_token *t, t_free *f)
{
	t_token *temp;
	t_token *node;
	char *newtok;
	t_token *befor;
	t_token *after;
	temp = t;
	while(temp)
	{
		if(ft_is_wrd_qot(temp) == 1 && ft_is_wrd_qot(temp->next) == 1)
		{
			newtok = ft_join_token(temp, temp->next, f);
			node = ft_create_node(newtok, _word, &f, NULL);
			befor = temp->previous;
			after = temp->next->next;
			node->previous = befor;
			node->next = after;
			if(befor != NULL)
				befor->next = node;
			if(after != NULL)
				after->previous = node;
			temp = t;// you must go bach to the begigng to start checking again
		}
		temp = temp->next;
	}
}

void ft_concatenate(t_token **t, t_free *f)
{
	
	t_token *node;
	t_token *temp;
	char *newtok;

	while(ft_is_wrd_qot(*t) == 1 && ft_is_wrd_qot((*t)->next) == 1)//in case we need to concatenate in the beginig - we will have to change the *t adress!!!!
	{
		newtok = ft_join_token(*t, (*t)->next, f);
		node = ft_create_node(newtok, _word, &f, NULL);
		temp = (*t)->next->next;
		if(temp != NULL)
			temp->previous = node;
		node->next = temp;
		*t = node;	
	}
	if((*t)->next == NULL || (*t)->next->next == NULL)
		return ;
	ft_if_its_inside(*t,f);// incase i need to concatinate inside the t_token linked test - no need for **t , just *temp;
}


