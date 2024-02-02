/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:14:51 by alcaball          #+#    #+#             */
/*   Updated: 2023/11/27 12:00:53 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*freeall(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (NULL);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	size_t	stt;
	size_t	j;
	char	*sub;

	j = 0;
	stt = (size_t) start;
	if (stt > ft_strlen(s) || s == NULL)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s + stt);
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (freeall(NULL, s));
	while (j < len)
	{
		sub[j] = s[stt];
		stt++;
		j++;
	}
	sub[j] = '\0';
	return (sub);
}

char	*ft_strjoin_gnl(char *line, char *bufline)
{
	char	*s3;
	int		i;
	int		j;

	s3 = malloc (sizeof(char) * (ft_strlen(line) + ft_strlen(bufline) + 1));
	if (!s3)
		return (freeall(bufline, line));
	i = 0;
	j = 0;
	while (line != NULL && line[i] != 0)
	{
		s3[i] = line[i];
		i++;
	}
	while (bufline[j] != 0 && bufline != NULL)
	{
		s3[i] = bufline[j];
		i++;
		j++;
	}
	s3[i] = 0;
	free(line);
	return (s3);
}
