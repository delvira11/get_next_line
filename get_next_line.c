/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delvira- <delvira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:05:43 by delvira-          #+#    #+#             */
/*   Updated: 2022/11/01 03:14:24 by delvira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <string.h>

char	*ft_readline(int fd, char *stash)
{
	char		*buf;
	int			n_bytes;

	n_bytes = 1;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	while (ft_strchr(buf, '\n') == 0 && n_bytes != 0)
	{
		n_bytes = read(fd, buf, BUFFER_SIZE);
		buf[n_bytes] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	free (buf);
	return (stash);
}


char	*ft_get_line(char *stash)
{
	char	*str;
	int		i;

	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	str = malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		str[i] = stash[i];
		i++;
	}
	str[i] = stash[i];
	if(str[i] == '\n')
		str[i+1] = '\0';
	return (str);
}

char	*ft_leftstr(char *stash)
{
	//crear y liberar memoria
	char	*str;
	char	*str2;
	int		i;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	str2 = malloc((ft_strlen(stash) - i + 1) * sizeof(char));
	if (!str2)
		return (NULL);
	str = ft_strchr(stash, '\n');
	if (!str)
		return(NULL);
	if (str[0] == '\n')
	{
		str2 = &str[1];
	}
	i = 0;
	while (str2[i] != '\0')
		i++;
	str2[i] = '\0';
	return (str2);	
}

char	*get_next_line(int fd)
{
	static char	*stash = 0;
	char		*line;

	stash = ft_readline(fd, stash);
	if (*stash == '\0')
		return (NULL);
	line = ft_get_line(stash);
	stash = ft_leftstr(stash);
	return (line);
}

int	main(void)
{
	char	*amd;

	amd = get_next_line(0);
	printf("%s", amd);
	amd = get_next_line(0);
	printf("%s", amd);
	amd = get_next_line(0);
	printf("%s", amd);
	amd = get_next_line(0);
	printf("%s", amd);
	system("leaks -q a.out");
	free(amd);
	return (0);
}