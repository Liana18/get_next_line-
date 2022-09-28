/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:42:07 by lter-zak          #+#    #+#             */
/*   Updated: 2022/08/19 16:35:46 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h>

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
	static char	*buff;
	char		*line1;
	char		*line2;
	long		len;

	len = 0;
	buff = line_ret(buff, fd);
	if (!buff)
		return (0);
	len = ft_strlen(buff) - ft_strlen(ft_strchr(buff, '\n')) + 1;
	line1 = ft_substr(buff, 0, len);
	line2 = buff;
	buff = ft_substr(buff, len, ft_strlen(buff));
	free(line2);
	return (line1);
}
//int main(){
//	
//	int fd;
//	
//	fd = open("text.txt" ,O_RDONLY);
//	printf("%s"  , get_next_line(fd));
//}
