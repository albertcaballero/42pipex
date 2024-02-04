/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:13:42 by alcaball          #+#    #+#             */
/*   Updated: 2024/02/04 11:09:35 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	*my_malloc(size_t size)
{
	void	*thing;

	thing = malloc(size);
	if (thing == NULL)
	{
		perror("malloc");
		exit(errno);
	}
	else
		return (thing);
}

void	close_pipes_fds(t_pipex key, int *stdtmp)
{
	duptemp(stdtmp, OUT);
	if (key.fd[0].fd != -1)
		close(key.fd[0].fd);
	if (key.fd[0].fd != -1)
		close(key.fd[1].fd);
	if (key.f_here)
		unlink("/tmp/herepipex");
}

void	duptemp(int *stdtmp, int flag)
{
	if (flag == IN)
	{
		stdtmp[0] = dup(STDIN_FILENO);
		stdtmp[1] = dup(STDOUT_FILENO);
		if (stdtmp[0] < 0 || stdtmp[1] < 0)
			ft_error(errno, NULL);
	}
	if (flag == OUT)
	{
		if (dup2(stdtmp[0], STDIN_FILENO) < 0)
			ft_error(errno, NULL);
		if (dup2(stdtmp[1], STDOUT_FILENO) < 0)
			ft_error(errno, NULL);
		if (close(stdtmp[0]) < 0)
			ft_error(errno, NULL);
		if (close(stdtmp[1]) < 0)
			ft_error(errno, NULL);
	}
}
