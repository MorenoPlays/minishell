/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <eda-mata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:46:00 by eda-mata          #+#    #+#             */
/*   Updated: 2024/10/24 15:53:32 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	echo(char **str)
{
	int	verify;
    int i;
    int j;

    i = 1;
	verify = 0;
    j = 1;
	if(ft_strcmp (str[i],"-n")==0)
	{
		++i;
        while(str[i][j] == 'n')
            j++;
        if(!str[i][j])
		    verify=1;
	}
	if(ft_strcmp(str[i],"|")==0)
		return (1);
	while(((str[i] != NULL) && ft_strcmp(str[i],"|") < 0 ) && (!(ft_strcmp(str[i],">>")==0) && !(ft_strcmp(str[i],">")==0)))
	{
		printf("%s", str[i]);
        if(str[i+1])
            printf(" ");
		i++;
	}
    if(verify==0)
        printf("\n");
	return (i);
}