/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:44:17 by alcaball          #+#    #+#             */
/*   Updated: 2023/09/18 16:19:30 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	test_file_acc(char *f1, char *f2)
{
	if (access(f1, F_OK) < 0 || access(f2, F_OK))
		return (-1);
	return (0);
}

t_comm	parse_comms(char *c1, char **envp)
{
	t_comm	cmd;
	char	*path_envp;
	char	**paths;
	char	**commands;

	path_envp = ft_substr(envp[11], 5, ft_strlen(envp[11]) - 5);
	paths = ft_split(path_envp, ':');
	commands = ft_split(c1, ' ');
	cmd.arg = commands;
	cmd.path = paths;
	free(path_envp);
	return (cmd);
}
