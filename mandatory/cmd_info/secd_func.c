/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secd_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:34:19 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/07/13 16:34:25 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_count(t_token *temp)
{
	int count;

	count = 0;
	while(temp && temp->type != _pipe)
	{
		if(ft_is_a_redirection(temp) == 1)
			temp = temp->next;
		else
			count++;
		temp = temp->next;
	}
	return (count);
}

void ft_protect(void *ptr, t_free *f)
{
	if(ptr == NULL)
	{
		ft_free_all(f);
		exit (1);
	}
}

void ft_add_back_t_red(t_red **r, t_red *node)
{
	t_red *temp;
	
	temp = *r;
	if(*r == NULL)
		*r = node;
	else
	{
		while(temp)
		{
			if(temp->next == NULL)
				break;
			temp = temp->next;
		}
		temp->next = node;
	}
	
}

t_token *ft_next_part(t_token *temp)
{
	while(temp)
	{
		if(temp->type == _pipe)
		{
			temp = temp->next;
			break;
		}
		temp = temp->next;
	}
	return (temp);
}

