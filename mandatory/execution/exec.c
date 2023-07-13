/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:54:23 by ataouaf           #+#    #+#             */
/*   Updated: 2023/07/12 18:35:44 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../exec.h"

void    exec(t_cmd *cmd, t_env *env)
{
    t_exec *exec;

    exec = init_exec(cmd, env);
    if (!exec)
        return ;
    // exec->count_cmd = count_cmd(cmd);
    exec->cmds = init_arr_cmd(exec, cmd->comand);
    // exec->tokens = init_arr_cmd(exec, 0);
    // while (exec->cmds[i])
    // {
    //     int j = 0;
    //     if (!exec->cmds[i])
    //         return ;
    //     while (exec->cmds[i][j])
    //     {
    //         printf("exec->cmds[%d][%d] = %s\n", i, j, exec->cmds[i][j]);
    //         j++;
    //     }
    //     i++;        
    // }
    
    // printf("exec->count_cmd = %d\n", exec->count_cmd);
    // printf("exec->cmds[0][0] = %s\n", exec->cmds[0][0]);
    // printf("exec->cmds[0][1] = %s\n", exec->cmds[0][1]);
    // printf("exec->cmds[1][0] = %s\n", exec->cmds[1][0]);
    // printf("exec->cmds[1][1] = %s\n", exec->cmds[1][1]);
    // printf("exec->cmds[2][0] = %s\n", exec->cmds[2][0]);
    // printf("exec->cmds[2][1] = %s\n", exec->cmds[2][1]);
}
