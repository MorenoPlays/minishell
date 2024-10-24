/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <eda-mata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:37:30 by eda-mata          #+#    #+#             */
/*   Updated: 2024/10/24 16:17:39 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    intern(t_cmd *cmd,char **environ)
{
    int pid;
    t_cmd *aux;

    aux = cmd;
    if(pid==0)
    {
        if(ft_strcmp(aux->comand,"echo")==0)
            echo(aux->parm);
        return ;
    }
}