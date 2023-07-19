/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:04:11 by ataouaf           #+#    #+#             */
/*   Updated: 2023/07/12 18:35:38 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../exec.h"

int	ft_array_size(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

t_exec  *init_exec(t_cmd *cmd, t_env *env)
{
    t_exec  *exec;

    exec = malloc(sizeof(t_exec));
    if (!exec)
    {
        perror("malloc");
        return (NULL);
    }
    exec->cmds = NULL;
    exec->tokens = NULL;
    while (cmd)
    {
        exec->old_cmd = cmd->comand;
        cmd = cmd->next;
    }
    exec->old_token = NULL;
    exec->count_cmd = count_cmd(cmd);
    exec->cpid = NULL;
    exec->env = &env;
    return (exec);
}
char ***init_arr_cmd(t_exec *exec, char **command)
{
    char    ***arr_cmd;
    int     i;

    arr_cmd = malloc(sizeof(char **) * (exec->count_cmd + 1));
    if (!arr_cmd)
    {
        perror("malloc");
        return (NULL);
    }
    arr_cmd[exec->count_cmd] = NULL;
    i = 0;
    int j = 0;
    while (exec->old_cmd[i])
    {
        arr_cmd[j] = get_next_cmd(exec, &command[i]);
        i += ft_array_size(arr_cmd[j]);
        if (exec->old_cmd[i])
            i++;
        j++;
        i++;
    }
    return (arr_cmd);
}

// int    **init_arr_token(t_exec *exec, int save)
// {
//     int     **arr_token;
//     int     i;

//     arr_token = malloc(sizeof(int *) * (exec->count_cmd + 1));
//     if (!arr_token)
//         return (NULL);
//     arr_token[exec->count_cmd] = NULL;
//     i = 0;
//     while (i < exec->count_cmd)
//     {
//         arr_token[i] = malloc(sizeof(int) * (ft_array_size(exec->cmds[i]) + 1));
//         int j = 0;
//         while (exec->old_token[j] != 0)
//         {
//             arr_token[i][j] = exec->old_token[j];
//             j++;
//         }
//         arr_token[i][j] = 0;
//         save += j + 1;
//         i++;
//     }
//     return (arr_token);
// }
