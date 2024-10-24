/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <eda-mata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:02:20 by eda-mata          #+#    #+#             */
/*   Updated: 2024/10/24 15:02:08 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H
#include <readline/readline.h>
#include <readline/history.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

extern int sinal;

typedef struct s_cmd
{
    char *comand;
    char **parm;
    struct s_cmd *next;
}t_cmd;

void    reprompt(int sig);
char **ft_split_expand(char *str);
void    input_param(char *cmd, char **environ);
int	ft_strcmp(char *s1, char *s2);
char	**ft_strdup2(char **str);
int countmatriz(char **params);
int	echo(char **str);
void    intern(t_cmd *cmd,char **environ);

#endif