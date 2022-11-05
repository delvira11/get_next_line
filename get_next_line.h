/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: delvira- <delvira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:02:41 by delvira-          #+#    #+#             */
/*   Updated: 2022/11/05 20:37:41 by delvira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    GET_NEXT_LINE_H
# define    GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

size_t	ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_readline(int fd, char *stash);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char *stash, char *buf);
char	*ft_get_line(char *stash);
char	*get_next_line(int fd);
char	*ft_strjoinnomalloc(char *stash, char *buf, char *str);

#endif
