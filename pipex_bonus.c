/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albert <albert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:35:29 by albert            #+#    #+#             */
/*   Updated: 2023/11/26 13:41:05 by albert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(t_fd f1, t_comm cmd1, int *pipes, char **envp)
{
	int	ret;

	close (pipes[0]);
	check_file_permissions(&f1);
	if (f1.perm != 0)
		ft_error(f1.perm, f1.name);
	check_cmd_permissions(&cmd1);
	if (cmd1.perm != 0)
		ft_error(cmd1.perm, cmd1.name);
	if (dup2(f1.fd, STDIN_FILENO) < 0)
		ft_error(404, f1.name);
	if (dup2(pipes[1], STDOUT_FILENO) < 0)
		ft_error(errno, NULL);
	close (f1.fd);
	ret = execve(cmd1.path, cmd1.arg, envp);
	if (ret == -1)
		ft_error(127, cmd1.arg[0]);
}

void	child2(t_fd f2, t_comm cmd2, int *pipes, char **envp)
{
	int	ret;

	close (pipes[1]);
	check_file_permissions(&f2);
	if (f2.perm != 0)
		ft_error(f2.perm, f2.name);
	check_cmd_permissions(&cmd2);
	if (cmd2.perm != 0)
		ft_error(cmd2.perm, cmd2.name);
	if (dup2(pipes[0], STDIN_FILENO) < 0)
		ft_error(404, f2.name);
	if (dup2(f2.fd, STDOUT_FILENO) < 0)
		ft_error(errno, NULL);
	close(f2.fd);
	close(pipes[0]);
	ret = execve(cmd2.path, cmd2.arg, envp);
	if (ret == -1)
		ft_error(127, cmd2.arg[0]);
}

void	pipex(t_pipex key, t_comm *cmd, char **envp)
{
	pid_t	sig[key.argc]; //another VSA
	int		pipes[key.argc][2]; //another VSA
	int		status;

	pipe (pipes[0]);
	sig[0] = fork();
	if (sig[0] < 0)
		ft_error(errno, NULL);
	else if (sig[0] == 0)
		child(key.fd[0], cmd[0], pipes[0], envp);
	sig[1] = fork();
	if (sig[1] < 0)
		ft_error(errno, NULL);
	else if (sig[1] == 0)
		child2(key.fd[1], cmd[1], pipes[0], envp);
	close (pipes[0]);
	close (pipes[1]);
	close(key.fd[0].fd);
	close(key.fd[1].fd);
	waitpid(sig[1], &status, 0);
	if (WEXITSTATUS(status) != 0)
		exit(WEXITSTATUS(status));
}

void	ft_free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	main(int argc, char **argv, char **envp)
{
	t_comm	cmd[argc - 3]; //idk if it counts as a VSA??
	t_pipex	key;
	char	**paths;

	if (argc < 5)
		return(write(2, "Pipex: Wrong Argument Count\n", 28), 1);
	key.argc = argc;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		funct_here_doc(); //no existe aun :)
	key.fd[0].name = argv[1];
	key.fd[1].name = argv[argc - 1];
	key.fd[0].fd = open(key.fd[0].name, O_RDONLY);
	key.fd[1].fd = open(key.fd[1].name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	paths = check_path_var(envp);
	cmd[0] = parse_comms(argv[2], paths);
	cmd[1] = parse_comms(argv[3], paths);
	ft_free_split(paths);
	pipex(key, cmd, envp);
	ft_free_split(cmd[0].arg);
	ft_free_split(cmd[1].arg);
	exit(EXIT_SUCCESS);
}
