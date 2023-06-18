/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:21:36 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/06/18 20:22:05 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void ft_add_address(t_free **ptr, t_free *new)
{
	t_free *temp;

	temp = *ptr;
	if(*ptr == NULL)
		*ptr = new;
	else 
	{
		while(temp)
		{
			if(temp->next == NULL)
				break;
			temp = temp->next;
		}
		temp->next = new;	
	}
}

void ft_add_t_free_node(t_free **f, t_free *node)
{
	t_free *temp;

	if(*f == NULL)
		f = temp;
	else
	{
		while(temp)
		{
			if(temp->next == NULL)
				break ;
			temp = temp->next;
		}
		temp->next = node;
	}
}

void ft_create_t_free_node(void *add, t_free *f)
{
	t_free *node;

	node = malloc(sizeof(t_free));
	if(node == NULL)
		ft_free_all(f);
	node->address = add;
	node->next = NULL;
	return node;
}

void ft_free_all(t_free *f)
{
	t_free *node_saver;
	while(f)
	{
		node_saver = f;
		f = f->next;
		free(node_saver->address);
		free(node_saver);
	}
}
