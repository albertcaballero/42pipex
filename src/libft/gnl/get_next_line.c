/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 12:51:16 by alcaball          #+#    #+#             */
/*   Updated: 2023/11/27 12:01:36 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	end_check(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*getliner(char *temp)
{
	int		i;
	char	*mega;

	i = 0;
	mega = NULL;
	if (temp == NULL || temp[0] == '\0')
		return (NULL);
	while (temp[i] != 10 && temp[i] != 0)
		i++;
	if (temp[i] == 10)
		mega = malloc (sizeof(char) * (i + 2));
	else if (temp[i] == 0)
		mega = malloc (sizeof(char) * (i + 1));
	if (!mega)
		return (NULL);
	i = 0;
	while (temp[i] != 10 && temp[i] != 0)
	{
		mega[i] = temp[i];
		i++;
	}
	if (temp[i] == 10)
		mega[i++] = 10;
	mega[i] = 0;
	return (mega);
}

static char	*colador(char *cola, size_t megalen)
{
	int		i;
	char	*temp;

	i = 0;
	if (ft_strlen(cola) == megalen)
		return (freeall(cola, NULL));
	temp = ft_substr_gnl(cola, megalen, ft_strlen(cola) - megalen);
	if (temp == NULL)
		return (NULL);
	while (cola[megalen] != 0)
		temp[i++] = cola[megalen++];
	temp[i] = 0;
	free(cola);
	return (temp);
}

static char	*reader(int fd, char *cola)
{
	int		readbytes;
	char	*bufferline;

	readbytes = 1;
	bufferline = malloc (BUFFER_SIZE + 1);
	if (!bufferline)
		return (freeall(NULL, cola));
	while (end_check(cola) == 0 && readbytes > 0)
	{
		readbytes = read(fd, bufferline, BUFFER_SIZE);
		if (readbytes < 0)
			return (freeall(cola, bufferline));
		else if (readbytes > 0)
		{
			bufferline[readbytes] = 0;
			cola = ft_strjoin_gnl(cola, bufferline);
			if (!cola)
				return (NULL);
		}
	}
	free(bufferline);
	return (cola);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*mega;
	static char	*cola;

	i = 0;
	mega = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cola = reader(fd, cola);
	if (cola == NULL)
		return (NULL);
	mega = getliner(cola);
	if (mega == NULL)
	{
		free(cola);
		cola = NULL;
	}
	else
		cola = colador(cola, ft_strlen(mega));
	return (mega);
}
