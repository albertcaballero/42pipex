/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albert <albert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:44:17 by alcaball          #+#    #+#             */
/*   Updated: 2023/11/26 13:16:12 by albert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_cmd_permissions(t_comm *cmd)
{
	cmd->perm = 0;
	if (access(cmd->path, F_OK) < 0)
		cmd->perm = NOCOMMAND;
	else if (access(cmd->path, X_OK) < 0)
		cmd->perm = NOXECUTE;
}

void	check_file_permissions(t_fd *fd)
{
	fd->perm = 0;
	if (access(fd->name, F_OK) < 0)
		fd->perm = NOFILE;
	else if (access(fd->name, R_OK) < 0)
		fd->perm = NOREAD;
	else if (access(fd->name, W_OK) < 0)
		fd->perm = NOWRITE;
}

char	**check_path_var(char **envp)
{
	int		i;
	int		j;
	char	**paths;
	char	*environment;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strnstr(envp[i], "PATH", 4) != NULL)
			j = i;
		i++;
	}
	environment = ft_substr(envp[j], 5, ft_strlen(envp[j]) - 5);
	paths = ft_split(environment, ':');
	free(environment);
	return (paths);
}

void	ft_free_cmd(t_comm *cmds)
{
	free(cmds[0].path);
	free(cmds[1].path);
	ft_free_split(cmds[0].arg);
	ft_free_split(cmds[1].arg);
}

t_comm	parse_comms(char *c1, char **paths)
{
	t_comm	cmd;
	int		i;
	char	*temp;

	i = 0;
	cmd.arg = ft_split(c1, ' ');
	cmd.name = cmd.arg[0];
	if (access(cmd.arg[0], R_OK) == 0)
	{
		cmd.path = cmd.arg[0];
		return (cmd);
	}
	while (paths[i] != NULL)
	{
		temp = ft_strjoin(paths[i], "/");
		cmd.path = ft_strjoin(temp, cmd.arg[0]);
		free (temp);
		if (access(cmd.path, R_OK) == 0)
			return (cmd);
		i++;
		free(cmd.path);
	}
	return (cmd);
}
