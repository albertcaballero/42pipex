/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:13:42 by alcaball          #+#    #+#             */
/*   Updated: 2024/01/25 17:19:07 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipes_fds(int *pipes, t_pipex key)
{
	close(pipes[0]);
	close(pipes[1]);
	close(key.fd[0].fd);
	close(key.fd[1].fd);
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
