/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:38:49 by alcaball          #+#    #+#             */
/*   Updated: 2024/02/02 11:55:51 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	check_eof(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			if (s2[i] == '\n')
				return (0);
			return (1);
		}
		i++;
	}
	return (0);
}

int	write_heredoc(char *eof)
{
	char	*line;
	int		tmpfd;

	tmpfd = open("/tmp/herepipex", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (tmpfd < 0)
		return (ft_error(errno, "error opening heredoc"), 1);
	while (1)
	{
		write(1, ">", 1);
		line = get_next_line(0);
		if (line == NULL)
			break ;
		if (check_eof(eof, line) == 0)
			break ;
		ft_putstr_fd(line, tmpfd);
		free(line);
	}
	free(line);
	close (tmpfd);
	tmpfd = open("/tmp/herepipex", O_RDONLY);
	return (tmpfd);
}
