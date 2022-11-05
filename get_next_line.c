/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delvira- <delvira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:05:43 by delvira-          #+#    #+#             */
/*   Updated: 2022/11/05 20:40:55 by delvira-         ###   ########.fr       */
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
	while (!ft_strchr(stash, '\n') && n_bytes != 0)
	{
		n_bytes = read(fd, buf, BUFFER_SIZE);
		if (n_bytes == -1)
		{
			free(buf);
			free(stash);
			return (NULL);
		}
		buf[n_bytes] = '\0';
		stash = ft_strjoin(stash, buf);
		if (!stash)
			break ;
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
	if (str[i] == '\n')
		str[i + 1] = '\0';
	return (str);
}

char	*ft_leftstr(char *stash)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (stash[i] != '\0' && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	str = malloc((ft_strlen(stash) - i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (stash[i] != '\0')
	{
		str[j++] = stash[i++];
	}
	str[j] = '\0';
	free(stash);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stash = 0;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = ft_readline(fd, stash);
	if (!stash)
	{
		free (stash);
		return (NULL);
	}
	line = ft_get_line(stash);
	stash = ft_leftstr(stash);
	return (line);
}

// int	main(void)
// {
// 	char	*str;
// 	int fd = open("test", O_RDONLY);
// 	while (str)
// 	{
// 		str = get_next_line(fd);
// 		printf("\n%s", str);
// 	}
// 	system("leaks -q a.out");
// 	return (0);
// }
