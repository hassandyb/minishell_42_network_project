/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:21:36 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/06/21 15:24:04 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void *ft_create_t_free(void *add, t_free *f)
{
	t_free *node;

	node = malloc(sizeof(t_free));
	if(node == NULL)
	{
		ft_free_all(f);
		exit (1);
	}
	node->address = add;
	node->next = NULL;
	return node;
}

void ft_add_t_free(t_free **f, t_free *node)
{
	t_free *temp;

	temp = *f;

	if(*f == NULL)
		*f = node;
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

void ft_free_all(t_free *f)
{
	t_free *node_saver;
	while(f != NULL)
	{
		node_saver = f;
		f = f->next;
		if(node_saver->address != NULL)
			free(node_saver->address);
		free(node_saver);
	}

}

void ft_protection(char *to_check, char *optional, t_free *f)
{
	if(to_check == NULL)
	{
		if(optional != NULL)
			free (optional);
		ft_free_all(f);
		exit (1);
	}
}


