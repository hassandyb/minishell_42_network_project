/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:41:20 by ataouaf           #+#    #+#             */
/*   Updated: 2023/08/05 14:37:22 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../exec.h"
// int	check_characters(const char *line, const char *charset)
// {
// 	int	i;
// 	int	state;
// 	int	j;

// 	i = 0;
// 	state = 0;
// 	while (line[i])
// 	{
// 		ft_check_state(&state, line[i]);
// 		j = 0;
// 		while (state == 0 && charset[j])
// 		{
// 			if (line[i] == charset[j])
// 			{
// 				dprintf(2, "minishell: syntax error: `%c' in input\n",
// 					charset[j]);
// 				return (0);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// int	check_pipe(const char *line)
// {
// 	if (line[0] == '|')
// 	{
// 		dprintf(2, "minishell: syntax error near unexpected token `|'\n");
// 		return (0);
// 	}
// 	return (1);
// }

// static int	check_unclosed_quote(const char *line)
// {
// 	int	i;
// 	int	state;

// 	i = 0;
// 	state = 0;
// 	while (line[i])
// 	{
// 		ft_check_state(&state, line[i]);
// 		i++;
// 	}
// 	if (state == 1)
// 	{
// 		dprintf(2, "minishell: ' not closed\n");
// 		return (0);
// 	}
// 	else if (state == 2)
// 	{
// 		dprintf(2, "minishell: \" not closed\n");
// 		return (0);
// 	}
// 	return (1);
// }

// static int	check_operators(const char *line, const char c, const int nb)
// {
// 	(void)nb;
// 	int	i;
// 	int	state;
// 	int	cnt_operator;

// 	i = -1;
// 	state = 0;
// 	while (line[++i])
// 	{
// 		ft_check_state(&state, line[i]);
// 		cnt_operator = 0;
// 		while (line[i] && state == 0 && line[i] == c)
// 		{
// 			cnt_operator++;
// 			i++;
// 			ft_check_state(&state, line[i]);
// 		}
// 		// if (state == 0 && cnt_operator > nb)
// 		// {
// 		// 	dprintf(2, E_OPERATOR_PARSE);
// 		// 	g_exit_status = 0;
// 		// 	return (0);
// 		// }
// 		if (!line[i])
// 			break ;
// 	}
// 	return (1);
// }

// static int	check_unsupported_operators(const char *line)
// {
// 	int	i;
// 	int	state;

// 	i = 0;
// 	state = 0;
// 	while (line[i])
// 	{
// 		ft_check_state(&state, line[i]);
// 		if ((state == 0 && line[i] == '>') || (state == 0 && line[i] == '<'))
// 		{
// 			if ((line[i] == '>' && line[i + 1] == '<') || (line[i] == '<'
// 					&& line[i + 1] == '>'))
// 			{
// 				dprintf(2, "minishell: syntax error: unexpected operator\n");
// 				return (0);
// 			}
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// int	check_empty_line(char *line)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i] && (line[i] == 32 || (line[i] >= 9 && line[i] <= 13)))
// 		i++;
// 	if (line[i] == 0)
// 		return (1);
// 	return (0);
// }





void ft_print_t_token_linked_list(t_token *t)
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




int	parse_line(char *command, t_token **token_lst, t_env **env_lst, char **envp)
{
	*env_lst = ft_get_env(envp);
	ft_create_tokens(token_lst, command);
	ft_print_t_token_linked_list(*token_lst);
	if (!ft_parsing(*token_lst))
	{
		return (0);
	}

	return (1);
}
