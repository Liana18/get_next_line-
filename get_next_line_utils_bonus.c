/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 22:36:26 by lter-zak          #+#    #+#             */
/*   Updated: 2022/06/06 22:53:43 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

char	*ft_strchr(char *str, int c)
{
	unsigned int	i;
	unsigned char	*s;
	size_t			len;

	s = (unsigned char *) str;
	len = ft_strlen(str);
	i = 0;
	if (c == 0)
		return ((char *)s + len);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;
	size_t	l;

	i = -1;
	j = -1;
	l = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((l + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[++i])
	{
		str[i] = s1[i];
	}
	while (s2[++j])
	{
		str[i++] = s2[j];
	}
	str[i] = '\0';
	if (s1)
		free(s1);
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	k;

	i = 0;
	if (start > ft_strlen(s))
		k = 0;
	else if (ft_strlen(s) - start > len)
		k = len;
	else
		k = ft_strlen(s) - start;
	str = (char *) malloc(k * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[i] && len > 0 && start < ft_strlen(s))
	{
		str[i++] = s[start++];
		len--;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(char *s1)
{
	char	*s;
	int		i;

	i = 0;
	s = (char *)malloc(ft_strlen(s1) * sizeof(char));
	if (!s)
		return (NULL);
	while (s[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = 0;
	return (s);
}
