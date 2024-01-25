/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:38:49 by alcaball          #+#    #+#             */
/*   Updated: 2024/01/25 13:46:48 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	write_heredoc(char *eof)
{
	char	*line;
	int		tmpfd;

	line = NULL;
	tmpfd = open("/tmp/herepipex", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (tmpfd < 0)
		return (ft_error_msg(1, "error opening heredoc"), 1);
	while (1)
	{
		write(1, ">", 1);
		line = get_next_line(tmpfd);
		if (line == NULL)
			break ;
		if (ft_strncmp(eof, line, ft_strlen(eof)) == 0)
			break ;
		ft_putstr_fd(line, tmpfd);
		free(line);
	}
	free(line);
	close (tmpfd);
	tmpfd = open("/tmp/herepipex", O_RDONLY);
	return (tmpfd);
}
