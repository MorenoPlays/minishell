/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <eda-mata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 07:57:56 by eda-mata          #+#    #+#             */
/*   Updated: 2024/10/24 14:40:04 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int sinal;

int main()
{
    char *cmd;
    char **params;
    extern char **environ;

    signal(SIGQUIT,SIG_IGN);
    signal(SIGINT,&reprompt);
    sinal=0;
    while(1)
    {
        cmd=readline("prompt% ");
        if(!cmd)
            break;
        input_param(cmd, environ);
        add_history(cmd);
        free(cmd);
    }
}