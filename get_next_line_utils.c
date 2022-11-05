/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delvira- <delvira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:22:39 by delvira-          #+#    #+#             */
/*   Updated: 2022/11/05 20:42:26 by delvira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
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
	if (!stash[0] && !buf[0])
	{
		free (stash);
		return (NULL);
	}
	str = malloc((ft_strlen(stash) + ft_strlen(buf) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str = ft_strjoinnomalloc(stash, buf, str);
	free(stash);
	return (str);
}

char	*ft_strjoinnomalloc(char *stash, char *buf, char *str)
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
