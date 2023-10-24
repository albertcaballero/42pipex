/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:35:29 by albert            #+#    #+#             */
/*   Updated: 2023/10/24 14:58:18 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(int f1, t_comm cmd1, int *pipes, char **envp)
{
	int	ret;

	close (pipes[0]);
	if (dup2(f1, STDIN_FILENO) < 0)
		ft_error(errno, NULL);
	if (dup2(pipes[1], STDOUT_FILENO) < 0)
		ft_error(errno, NULL);
	close (f1);
	ret = execve(cmd1.path, cmd1.arg, envp);
	if (ret == -1)
		ft_error(errno, NULL);
}

void	child2(int f2, t_comm cmd2, int *pipes, char **envp)
{
	int	ret;

	close (pipes[1]);
	if (dup2(pipes[0], STDIN_FILENO) < 0)
		ft_error(errno, NULL);
	if (dup2(f2, STDOUT_FILENO) < 0)
		ft_error(errno, NULL);
	close(f2);
	close(pipes[0]);
	ret = execve(cmd2.path, cmd2.arg, envp);
	if (ret == -1)
		ft_error(errno, NULL);
}

void	pipex(int *f, t_comm cmd1, t_comm cmd2, char **envp)
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
		child(f[0], cmd1, pipes, envp);
	sig2 = fork();
	if (sig2 < 0)
		ft_error(errno, NULL);
	else if (sig2 == 0)
		child2(f[1], cmd2, pipes, envp);
	close (pipes[0]);
	close (pipes[1]);
	close(f[0]);
	close(f[1]);
	if (waitpid(sig2, &status, 0) == -1)
		ft_error(errno, NULL);
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
	t_comm	cmd1;
	t_comm	cmd2;
	int		f[2];
	char	**paths;
	char	*environment;

	if (argc != 5)
		return (write(2, "Error: Wrong argument count\n", 28));
	test_file_acc(argv[1]);
	f[0] = open(argv[1], O_RDONLY);
	f[1] = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (f[0] == -1 || f[1] == -1)
		ft_error(errno, argv[1]);
	environment = ft_substr(envp[12], 5, ft_strlen(envp[12]) - 5);
	paths = ft_split(environment, ':');
	cmd1 = parse_comms(argv[2], paths);
	cmd2 = parse_comms(argv[3], paths);
	free(environment);
	pipex(f, cmd1, cmd2, envp);
	// ft_free(cmd1); solo queda hacer free cuando argv ya es un absolute path
	// ft_free(cmd2);
	exit(EXIT_SUCCESS);
}
