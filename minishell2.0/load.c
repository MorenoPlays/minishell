/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <eda-mata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:33:22 by eda-mata          #+#    #+#             */
/*   Updated: 2024/10/24 15:53:17 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int countmatriz(char **params)
{
    int i;

    i = 0;
    while (params[i])
    {
        i++;
    }
    return (i);
}

void    new_comand(t_cmd **cmd, char *comand, char **params)
{
    int i;
    t_cmd *aux;
    t_cmd *novo;
    t_cmd *last;

    i = 0;
    aux = *cmd;
    novo=malloc(1 * sizeof(t_cmd));
    if(aux==NULL)
    {
        novo->comand=comand;
        novo->parm=params;
        novo->next=NULL;
        (*cmd) = novo;
        return ;
    }
    while (aux)
    {
        last=aux;
        aux=aux->next;
    }
    novo->comand=comand;
    novo->parm=params;
    novo->next=NULL;
    aux = novo;
    last->next = aux;
    return ;
}

void    ft_input(t_cmd **cmd, char **params)
{
    char **arg;
    int i;
    int j;
    int argc;

    i = 0;
    while (params[i])
    {
        j = i;
        argc = 0;
        arg=malloc(countmatriz(params)+1 * sizeof(char *));
        while (params[i] && ft_strcmp(params[i], "|") != 0)
        {
            arg[argc]=params[i];
            i++;
            argc++;
        }
        arg[argc]=NULL;
        if(params[i])
            i++;
        new_comand(&*cmd,params[j],ft_strdup2(arg));
        free(arg);
    }
    
    
}

void    input_param(char *cmd, char **environ)
{
    char **params;
    int pid;
    t_cmd *raiz;
    t_cmd *aux;

    sinal=1;
    pid=fork();
    raiz=NULL;
    if(pid==0)
    {
        params=ft_split_expand(cmd);
        ft_input(&raiz, params);
        intern(raiz, environ);
        exit(0);
    }
    else
    {
        wait(NULL);
        sinal=0;
        return ;
    }
}