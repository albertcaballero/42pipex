/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:13:42 by alcaball          #+#    #+#             */
/*   Updated: 2024/02/02 15:31:45 by alcaball         ###   ########.fr       */
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

void	close_pipes_fds(int *pipes, t_pipex key)
{
	close(pipes[0]);
	close(pipes[1]);
	close(key.fd[0].fd);
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
	}
	if (flag == OUT)
	{
		dup2(stdtmp[0], STDIN_FILENO);
		dup2(stdtmp[1], STDOUT_FILENO);
		close(stdtmp[0]);
		close(stdtmp[1]);
	}
}
