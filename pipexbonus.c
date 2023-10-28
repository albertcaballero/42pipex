/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:35:29 by albert            #+#    #+#             */
/*   Updated: 2023/10/28 14:36:49 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(t_fd f1, t_comm cmd1, int *pipes, char **envp)
{
	int	ret;

	close (pipes[0]);
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

void	pipex(t_fd *f, t_comm *cmd, char **envp)
{
	pid_t	sig;
	pid_t	sig2;
	int		pipes[2];
	int		status;

	pipe (pipes);
	sig = fork();
	if (sig < 0)
		ft_error(errno, NULL);
	else if (sig == 0)
		child(f[0], cmd[0], pipes, envp);
	sig2 = fork();
	if (sig2 < 0)
		ft_error(errno, NULL);
	else if (sig2 == 0)
		child2(f[1], cmd[1], pipes, envp);
	close (pipes[0]);
	close (pipes[1]);
	close(f[0].fd);
	close(f[1].fd);
	waitpid(sig2, &status, 0);
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
	t_comm	cmd[2];
	int		ret;
	t_fd	fd[2];
	char	**paths;

	if (argc != 5)
		return (write(2, "Error: Wrong argument count\n", 28), 1);
	fd[0].name = argv[1];
	fd[1].name = argv[4];
	ret = access(fd[0].name, F_OK);
	fd[0].fd = open(fd[0].name, O_RDONLY);
	fd[1].fd = open(fd[1].name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	paths = check_path_var(envp);
	cmd[0] = parse_comms(argv[2], paths);
	cmd[1] = parse_comms(argv[3], paths);
	ft_free_split(paths);
	pipex(fd, cmd, envp);
	ft_free_split(cmd[0].arg);
	ft_free_split(cmd[1].arg);
	exit(EXIT_SUCCESS);
}
