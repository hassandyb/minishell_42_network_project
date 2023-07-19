/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:51:58 by ataouaf           #+#    #+#             */
/*   Updated: 2023/07/12 18:33:12 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

typedef struct s_exec
{
	char	***cmds;
	int		**tokens;
	char	**old_cmd;
	int		*old_token;
	int		heredoc_fd[16][2];
	int		pipe_fd[2][2];
	int		count_cmd;
	int		*cpid;
	t_env	**env;
}	t_exec;

void    exec(t_cmd *cmd, t_env *env);
int	count_cmd(t_cmd *cmd);
char **get_next_cmd(t_exec *exec, char **command);
t_exec  *init_exec(t_cmd *cmd, t_env *env);
char ***init_arr_cmd(t_exec *exec, char **cmd);
