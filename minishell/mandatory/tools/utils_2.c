/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 22:37:16 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/07/07 22:42:12 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int ft_find_char(char *str, char c)// put it in utils
{
	int i;

	i = 0;
	while(str && str[i])
	{
		if(str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char *ft_strjoin(char *s1, char *s2, t_free *f)
{
	int i;
	int j;
	char *result;
	i = -1;
	j = 0;
	if(!s1 || !s2)
		return (NULL);
	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	ft_protection(result, NULL, f);
	ft_add_t_free(&f, ft_create_t_free(result, f));
	while(s1[++i])
		result[i] = s1[i];
	while(s2[j])
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}

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
	ft_protection_2(result, NULL, f);
	ft_add_t_free(&f, ft_create_t_free(result, f));
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

