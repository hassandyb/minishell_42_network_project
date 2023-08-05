/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 11:51:40 by hed-dyb           #+#    #+#             */
/*   Updated: 2023/08/05 14:29:46 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "minishell.h"

int		g_exit_status = 0;



void	ft_envlst_clear(t_env **env)
{
	t_env	*tmp;
	t_env	*current;

	if (!*env)
		return ;
	current = *env;
	while (current != NULL)
	{
		current = current->next;
		tmp = current;
		current = current->next;
		free(tmp->var_name);
		if (tmp->value)
			free(tmp->value);
		free(tmp);
	}
	*env = NULL;
}

int	main(int argc, char **argv, char **env)
{
	t_token *token_lst = NULL;

	t_env *env_lst;
	char *command;
	(void)argv;

	g_exit_status = 0;
	if (argc != 1)
		exit(0);
	handle_signal(DEFAULT_SIGNAL);
	command = readline(RED "minishell$ " NC);
	while (command)
	{
		if (*command)
			add_history(command);
		if (parse_line(command, &token_lst, &env_lst, env))
			start_exec(&env_lst, command);
		ft_free_token(token_lst);
		token_lst = NULL;

		command = readline(RED "minishell$ " NC);
	}
	rl_clear_history();

	// ft_envlst_clear(&env_lst);
	dprintf(1, "exit\n");
	return (g_exit_status);
}
