/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 22:28:26 by lter-zak          #+#    #+#             */
/*   Updated: 2022/06/08 14:06:43 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*line_ret(char *line, int fd)
{
	char	start_from[BUFFER_SIZE + 1];
	long	i;

	while (1)
	{
		i = read(fd, start_from, BUFFER_SIZE);
		start_from[i] = '\0';
		if (i == -1)
			return (0);
		if (!line)
			line = ft_strdup(start_from);
		else
			line = ft_strjoin(line, start_from);
		if (ft_strchr(start_from, '\n') || i == 0)
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buff[OPEN_MAX];
	char		*line1;
	char		*line2;
	long		len;

	if (fd < 0 || fd > 65535 || BUFFER_SIZE <= 0)
		return (NULL);
	len = 0;
	buff[fd] = line_ret(buff[fd], fd);
	if (!buff[fd])
		return (0);
	len = ft_strlen(buff[fd]) - ft_strlen(ft_strchr(buff[fd], '\n')) + 1;
	line1 = ft_substr(buff[fd], 0, len);
	line2 = buff[fd];
	buff[fd] = ft_substr(buff[fd], len, ft_strlen(buff[fd]));
	free(line2);
	return (line1);
}

//#include <stdio.h>
//int main ()
//{
//	printf("%s", get_next_line(100000));
//}
