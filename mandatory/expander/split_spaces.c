/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:29:09 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/07/08 17:30:22 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ft_add_new_to_t(t_token **t, t_token *temp, t_token *new)
{
	t_token *prv;
	t_token *nxt;

	prv = temp->previous;
	nxt = temp->next;
	if(prv != NULL)
		prv->next = new;
	if(new != NULL)
		new->previous = prv;
	if(temp == *t)
		*t = new;
	while(new)
	{
		if(new->next == NULL)
			break;
		new = new->next;
	}
	if(new != NULL)
		new->next = nxt;
	if(nxt != NULL)
		nxt->previous = new;
}
	
void ft_split_spaces(t_token **t, t_free *f)
{
	t_token *temp;
	char **result = NULL;
	temp = *t;
	int i;
	t_token *new;

	new = NULL;
	while(temp)
	{
		i = 0;
		if(temp->type == _word && ft_find_char(temp->token, ' ') > 0)
		{
			result = ft_split(temp->token, ' ', f);

			while(result[i] != NULL)
			{
				ft_add_back(&new, ft_create_node(result[i], _word, &f, NULL));
				if(result[i + 1] != NULL)
				ft_add_back(&new, ft_create_node(" ", _white_space, &f, NULL));
				i++;
			}
			ft_add_new_to_t(t, temp, new);
		}
		temp = temp->next;
	}
}

