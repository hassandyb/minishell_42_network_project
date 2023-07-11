/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:51:58 by ataouaf           #+#    #+#             */
/*   Updated: 2023/07/11 10:53:50 by ataouaf          ###   ########.fr       */
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
