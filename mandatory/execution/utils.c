/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataouaf <ataouaf@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:42:37 by ataouaf           #+#    #+#             */
/*   Updated: 2023/07/12 16:01:45 by ataouaf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../exec.h"

int	count_cmd(t_cmd *cmd)
{
    int	count;

    if (!cmd)
        return (0);
    count = 0;
    while (cmd)
    {
        count++;
        cmd = cmd->next;
    }
    return (count);
}
char **get_next_cmd(t_exec *exec, char **command)
{
    char    **arr_cmd;

    int count = exec->count_cmd;
    arr_cmd = malloc(sizeof(char *) * (count + 1));
    if (!arr_cmd)
    {
        perror("malloc");
        return (NULL);
    }
    arr_cmd[count] = NULL;
    int i = 0;
    while (i < count)
    {
        arr_cmd[i] = command[i];
        i++;
    }
    return (arr_cmd);
}
