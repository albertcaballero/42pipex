/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albert <albert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:35:29 by albert            #+#    #+#             */
/*   Updated: 2023/12/17 01:20:33 by albert           ###   ########.fr       */
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

void	close_pipes_fds(int **pipes, t_pipex key)
{
	int	i;

	i = 0;
	while (i < key.argc - 2)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
	close(key.fd[0].fd);
	close(key.fd[1].fd);
}

void	pipex(t_pipex key, t_comm *cmd, char **envp)
{
	pid_t	*sig;
	int		**pipes;
	int		status;
	int		i;

	i = 0;
	sig = malloc (sizeof(pid_t) * (key.argc - 2));
	pipes = malloc(sizeof(int *) * (key.argc - 2));
	while (i < key.argc - 2)
	{
		pipes[i] = malloc (sizeof(int) * 2);
		pipe (pipes[i]);
		i++;
	}
	i = 0;
	while (i < key.argc - 2)
	{
		sig[i] = fork();
		if (sig[i] < 0)
			ft_error(errno, NULL);
		else if (sig[i] == 0)
			child(key.fd[0], cmd[0], pipes[0], envp);
		i++;
	}
	//maybe last child needs special treatment?
	close_pipes_fds(pipes, key);
	waitpid(sig[key.argc - 2], &status, 0);
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
	t_comm	*cmd;
	t_pipex	key;
	char	**paths;
	int		i;

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
	i = 0;
	cmd = malloc(sizeof(*cmd) * (argc - 3));
	while (i < argc - 3)
	{
		cmd[i] = parse_comms(argv[i + 2], paths);
		i++;
	}
	ft_free_split(paths);
	pipex(key, cmd, envp);
	i = 0;
	while (i < argc - 3)
		ft_free_split(cmd[i++].arg);
	exit(EXIT_SUCCESS);
}
