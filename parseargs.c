/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:44:17 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/25 16:53:20 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(int errcode, char	*str)
{
	if (errcode == 127)
	{
		ft_putstr_fd("Bash: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	else if (str)
	{
		ft_putstr_fd("Bash: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errcode), 2);
	}
	else
		perror("bash");
	if (errcode != 0)
		exit(errcode);
	else
		exit(EXIT_FAILURE);
}

void	ft_free(t_comm cmd)
{
	int	i;

	i = 0;
	free(cmd.path);
	while (cmd.arg[i])
	{
		free(cmd.arg[i]);
		i++;
	}
	free (cmd.arg);
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

t_comm	parse_comms(char *c1, char **paths)
{
	t_comm	cmd;
	int		i;
	char	*temp;

	i = 0;
	cmd.arg = ft_split(c1, ' ');
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
	ft_free_split(paths);
	ft_error(127, cmd.arg[0]);
	return (cmd);
}
