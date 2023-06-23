/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hed-dyb <hed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:51:40 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/06/23 21:54:55 by hed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_print_t_token_linked_list(t_token *t)//
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

void ft_print_t_env_linked_list(t_env *e)//
{
	if(e == NULL)
		printf("NULL\n");
		int i = 0;
	while(e)
	{
		printf("%d ==> %s      %s\n", i, e->var_name, e->value);
		i++;
		e = e->next;
	}
	printf("\n\n");
}

// tokenizer
// parcer
// expander
// conncater
// execution
//  ft_find_cha
//  0 = does not exist
//  1 = does exist 


char	*ft_substr(char *s, int start, int len, t_free *f)
{
	char	*result;
	int	i;

	i = 0;
	if(s == NULL )
		return NULL;
	
	result = (char *) malloc(len + 1);
	ft_protection(result, NULL, f);
	ft_add_t_free(&f, ft_create_t_free(result, f));
	while (s[i + start] != '\0' && i < len)
	{
		result[i] = s[i + start];
		i++;
	}
	result[i] = '\0';
	return (result);
}

t_env *ft_t_env_node(char *env_line, t_free *f)
{
	t_env *node;
	int i;
	int len;
	
	i = 0;
	node = malloc(sizeof(t_env));
	if(node == NULL)
	{
		ft_free_all(f);
		exit (0);
	}
	ft_add_t_free(&f, ft_create_t_free(node, f));
	while(env_line[i])
	{
		if(env_line[i] == '=')
			break;
		i++;
	}
	len = ft_strlen(env_line);
	node->var_name = ft_substr(env_line, 0, i, f);
	node->value = ft_substr(env_line, i + 1, len - i - 1, f);
	node->next = NULL;
	return node;
}

void ft_add_back_t_env(t_env **e, t_env *node)
{
	t_env *temp;
	
	temp = *e;
	if(*e == NULL)
	{
		*e = node;
		return ;
	}
	while(temp)
	{
		if(temp->next == NULL)
			break ;
		temp = temp->next;
	}
	temp->next = node;
}
//---------------------------------
// Env examples
// 0 ==> USER      hed-dyb
// 1 ==> MallocNanoZone      0
// 3 ==> LOGNAME      hed-dyb
// 5 ==> HOME      /Users/hed-dyb
// 6 ==> SHELL      /bin/zsh
// 7 ==> __CF_USER_TEXT_ENCODING      0x18F3C:0x0:0x0
// 9 ==> XPC_SERVICE_NAME      0
// 10 ==> XPC_FLAGS      0x0
// 11 ==> ORIGINAL_XDG_CURRENT_DESKTOP      undefined
// 12 ==> SHLVL      1
// 13 ==> PWD      /Users/hed-dyb/Desktop/minishell/mandatory
// 14 ==> OLDPWD      /Users/hed-dyb/Desktop/minishell
// 15 ==> ZSH      /Users/hed-dyb/.oh-my-zsh
// 16 ==> PAGER      less
// 17 ==> LESS      -R
// 18 ==> LSCOLORS      Gxfxcxdxbxegedabagacad
// 22 ==> TERM_PROGRAM      vscode
// 23 ==> TERM_PROGRAM_VERSION      1.79.2
// 24 ==> LANG      en_US.UTF-8
// 25 ==> COLORTERM      truecolor


// ft_special_cases()
	
	// if(node->token[begin + 1] == '_' && node->token[begin + 2] == '\0')
	// {
	// 	//do something;
	// }
	// if(node->token[begin + 1] == '_' && node->token[begin + 2] == '?')
	// {
	// 	//do something;
	// }
	//if()  dollar then a char who is not valid directly ...

int ft_islnum(char c)
{
	if(c >= '0' && c <= '9')
		return (1);
	if(c >= 'a' && c <= 'z')
		return (1);
	if(c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int ft_find_char(char *str, char c)
{
	int i;

	i = 0;
	while(str && str[i])
	{
		if(str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void ft_begin_and_end(char *token, int *begin, int *end)
{
	int i;

	i = 0;
	while(token && token[i])
	{
		if(token[i] == '$')
		{
			*begin = i;
			i++;
			break ;
		}
		i++;
	}
	while(token && token[i] && (ft_islnum(token[i]) == 1 || token[i] == '_'))
		i++;
	*end = i - 1;
}

char *ft_strdup(char *str, t_free *f)
{
	int i;
	char *copy;
	
	if(str == NULL)
		return (NULL);
	copy = malloc((ft_strlen(str) + 1) * sizeof(char));
	ft_protection(copy, NULL, f);
	ft_add_t_free(&f, ft_create_t_free(copy, f));
	i = 0;
	while(str[i])
	{
		copy[i] = str[i];	
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char *ft_get_var_value(t_env *e, char *var, t_free *f)
{
	int i;

	while(e)
	{
		i = 0;
		while((e->var_name[i] && var[i]) && e->var_name[i] == var[i] )
			i++;
		if(ft_strlen(var) == i &&  ft_strlen(e->var_name) == i)
			return(e->value);
		e = e->next;
	}
	return(ft_strdup("", f));
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

void ft_replace(t_token *node,t_env *e, t_free *f)
{
	int begin = 0;
	int end = 0;
	(void)e;

	char *var_value;
	char *befor;
	char *after;
	while(ft_find_char(node->token, '$') == 1)
	{
		ft_begin_and_end(node->token, &begin, &end);

		// ft_special_cases()
		befor = ft_substr(node->token, 0, begin, f);
		if(node->token[begin + 1] == '\0' || node->token[begin + 1] == '"')
			break ;
		var_value = ft_get_var_value(e, ft_substr(node->token, begin + 1, end - begin, f), f);
		befor = ft_strjoin(befor, var_value, f);
		after = ft_substr(node->token, end + 1, ft_strlen(node->token) - end - 1, f);
		node->token = ft_strjoin(befor, after, f);
		// if(ft_var_cases(node->token, '$', i) == 1 ) // var santax not valid
	}

	
}

void ft_expander(t_env **e, char **env, t_token **t, t_free *f)
{
	int i;
	t_token *temp;
	
	temp = *t;
	i = -1;
	if(*e == NULL)
	{
		while(env[++i])
			ft_add_back_t_env(e, ft_t_env_node(env[i], f));
			i++;
	}
	while(temp)
	{
		if(temp->type == _word || temp->type == _double_quote)
		{
			ft_replace(temp, *e, f);
		}
		temp = temp->next;
	}

}



int main (int argc, char **argv, char  **env)
{
	t_token *t;
	t_free  *f;
	char *command;
	t_env *e;
	(void)argv;
	e = NULL;
	if(argc != 1)
		exit (0);
	while(1)
	{
		t = NULL;
		f = NULL;
		command = readline("minishell= ");
		if(command == NULL)
			exit (0);
		add_history(command);
		ft_create_tokens(&t, command, &f);
		if(ft_parsing(t) == 0)
		{
			ft_free_all(f);
			continue ;
		}
				ft_print_t_token_linked_list(t);
		ft_expander(&e, env, &t, f);
				ft_print_t_token_linked_list(t);
				// ft_print_t_env_linked_list(e);

	}
	ft_free_all(f);	
}