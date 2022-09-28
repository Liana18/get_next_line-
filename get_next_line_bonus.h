/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 22:35:50 by lter-zak          #+#    #+#             */
/*   Updated: 2022/06/08 14:07:30 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*line_ret(char *line, int fd);

char		*get_next_line(int fd);

size_t		ft_strlen(char *str);

char		*ft_strchr(char *str, int c);

char		*ft_strjoin(char *s1, char *s2);

char		*ft_substr(char *s, unsigned int start, size_t len);

char		*ft_strdup(char *s1);

#endif
