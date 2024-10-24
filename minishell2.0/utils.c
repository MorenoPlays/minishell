/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <eda-mata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:18:31 by eda-mata          #+#    #+#             */
/*   Updated: 2024/10/24 14:12:39 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i]-s2[i]);
}

int	sep(char *str, char c)
{
	int	i;
	int	count;
	int	j;
	char	asp;


	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		if(str[i]=='"' || str[i] == 39)
		{
            count++;
			asp = str[i];
			i++;
			while (str[i]!=asp && str[i])
				i++;
			if (!str[i])
            {
				printf("Erro aspa sem fechamento!\n");
                exit(1);
            }
		}
        i++;
	}
	return (count);
}

int	fechamento(char *str, char c, int i)
{
	while(str[i])
	{
		if(str[i]==c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if(!str)
		return 1;
	while (str[i] != '\0')
		i++;
	return (i);
}

int expand(char **res, char *str, int k, int j)
{
	int i;

	i = 0;
	while(str[i])
	{
		res[k][j]=str[i];
		i++;
		j++;
	}
	res[k][j]='\0';
	return (j);
}

char	*getvar(char *str, int *i)
{
	int j;
	char *var;

	j=0;
	var = malloc(ft_strlen(str) * sizeof(char));
	(*i)++;
	while(str[(*i)] && (str[(*i)]>='a' && str[(*i)]<='z' || str[(*i)]>='A' && str[(*i)]<='Z'))
	{
		var[j]=str[(*i)];
		j++;
		(*i)++;
	}
	var[j]='\0';
	return (var);
	
}

int	mini_split_expand(char **sp, int i, char *str, int j)
{
	int	k;
	char *var;

	k = 0;
	j++;
	while(str[j] && str[j] != '"')
	{
		if(str[j]=='$')
		{
			var=getvar(str, &j);
			if(getenv(var))
			{
				k=expand(&*sp,getenv(var),i,k);
			}
		}
		if(str[j]=='"')
			break ;
		sp[i][k] = str[j];
		k++;
		j++;
	}
	sp[i][k]='\0';
	return (j+1);
}

int	mini_split(char **sp, int i, char *str, int j)
{
	int	k;
	char asp;

	k = 0;
	j++;
	while(str[j] && str[j]!=39)
	{
		sp[i][k] = str[j];
		k++;
		j++;
	}
	sp[i][k]='\0';
	return (j+1);
}

char **ft_split_expand(char *str)
{
	int i;
	int k;
	int j;
	char **res;
    char *var;

	i = 0;
	k = 0;
	j = 0;
	res=malloc(sep(str, ' ')+3 * sizeof(char *));
	while (i < sep(str, ' ') + 1)
	{
			res[i] = malloc((ft_strlen(str)+ft_strlen(str)+1) * sizeof(char));
			i++;
	}
	i=0;
	while(str[i])
	{
		j = 0;
		while(str[i]==' ' || str[i]=='	')
			i++;
		if(str[i]==39 && fechamento(str,39, i+1)==1)
		{
			i=mini_split(&*res, k, str, i);
		}
		else if(str[i]=='"' && fechamento(str,'"', i+1)==1)
		{
			i=mini_split_expand(&*res,k,str,i);
		}
		else
		{
			while((str[i] && str[i] != ' ') && (str[i] != '"' && str[i] != 39))
			{
                if(str[i]=='$')
		        {
			        var=getvar(str, &i);
			        if(getenv(var))
			        {
				        j=expand(&*res,getenv(var),k,j);
			        }
		        }
                else
                {
				    res[k][j]=str[i];
				    i++;
				    j++;
                }
			}
		res[k][j]='\0';
		}
		k++;
	}
	res[k]=NULL;
	return (res);
}

void	ft_strcpy(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str2[i])
	{
		str1[i] = str2[i];
		i++;
	}
	str1[i]='\0';
}

char	**ft_strdup2(char **str)
{
	int i;
	char **dup;

	i = 0;
	dup=malloc(countmatriz(str)+1 * sizeof(char*));
	while (str[i])
	{
		dup[i]=malloc(ft_strlen(str[i])+1 * sizeof(char));
		i++;
	}
	i = 0;
	while(str[i])
	{
		ft_strcpy(dup[i], str[i]);
		i++;
	}
	dup[i]=NULL;
	return (dup);
	
}