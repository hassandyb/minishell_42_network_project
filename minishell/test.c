/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:25:43 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/07/07 15:54:48 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


int ft_count_words(char *str, char c)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	//       abc  def  ghi
	while(str[i] == c)	
		i++;
	while(str[i])
	{
		if((str[i] == c && str[i + 1] != c) || str[i + 1] == '\0')
			counter++;
		i++;
	}
	return (counter);
}

char **ft_split(char *str, char c, t_free *f)
{
	int i;
	char **result;
	int j;
	int start;
	i = 0;
	j = 0;
	result = malloc((ft_count_words(str, c) + 1) * sizeof(char *));

	while(i < ft_count_words(str, c) && str[j])
	{
		while(str[j] == c)
			j++;
		start = j;
		while(str[j] != c && str[j] != '\0')
			j++;
		result[i] = ft_substr(str, start, j - start, f);
		i++;
	}
	result[i] = NULL;
	return (result);
}