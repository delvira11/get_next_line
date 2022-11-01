/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delvira- <delvira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:22:39 by delvira-          #+#    #+#             */
/*   Updated: 2022/11/01 01:24:35 by delvira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

// void printbuff(char *str, char *name)
// {
// 	int i = 0;
// 	char c = '\n';
// 	char *c3 = " * ";
// 	char c2 = '|';

// 	if(!str)
// 		return;

// 	write(1,&c,1);
// 	while (name[i] != '\0')
// 	{
// 		write(1,&name[i],1);
// 		i++;
// 	}
// 	write(1,":",1);

// 	write(1,&c2,1);
// 	i = 0;
// 	while(str[i] != '\0')
// 	{
// 		if(str[i] == c)
// 		{
// 			write(1,c3,4);
// 		}
// 		else
// 			write(1,&str[i],1);
// 		write(1,&c2,1);
// 		i++;
// 	}
// 	write(1,"$\\0$|",5);
// }


#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	char	caracter;

	caracter = c;
	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == caracter)
			return (&str[i]);
		i++;
	}
	if (str[i] == caracter)
		return (&str[i]);
	return (NULL);
}

char	*ft_strjoin(char *stash, char *buf)
{
	char			*str;
	if (!stash)
	{
		stash = malloc(1 * sizeof(char));
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	if (!stash || !buf)
		return (NULL);
	str = malloc((ft_strlen(stash) + ft_strlen(buf) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str = ft_strjoin_nomalloc(stash, buf, str);
	return (str);
}

char	*ft_strjoin_nomalloc(char *stash, char *buf, char *str)
{
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	while (stash[i])
	{
		str[i] = stash[i];
		i++;
	}
	while (buf[j])
	{
		str[i + j] = buf[j];
		j++;
	}
	str[i + j] = '\0';

	return (str);
}
