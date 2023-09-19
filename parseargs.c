/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:44:17 by alcaball          #+#    #+#             */
/*   Updated: 2023/09/19 14:02:09 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	test_file_acc(char *f1)
{
	ft_printf("hola");
	if (access(f1, F_OK) < 0)
		return (-1);
	ft_printf("holaaa");
	return (0);
}

t_comm	parse_comms(char *c1, char **envp)
{
	t_comm	cmd;
	char	*path_envp;
	char	**paths;
	char	**commands;
	int		i;

	i = 0;
	path_envp = ft_substr(envp[11], 5, ft_strlen(envp[11]) - 5);
	paths = ft_split(path_envp, ':');
	commands = ft_split(c1, ' ');
	cmd.arg = commands;
	while (paths[i] != NULL)
	{
		if (access(ft_strjoin(ft_strjoin(paths[i], "/"), c1), F_OK) == 0)
			cmd.path = paths[i];
		i++;
	}
	free(path_envp);
	ft_printf("jeu");
	return (cmd);
}
