/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:35:29 by albert            #+#    #+#             */
/*   Updated: 2023/09/19 17:27:02 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(int errcode)
{
	if (errcode == 1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}

void	child(int f1, t_comm cmd1, int *pipes, char **envp)
{
	int	ret;

	if (dup2(f1, STDIN_FILENO) < 0)
		ft_error(1);
	if (dup2(pipes[1], STDOUT_FILENO) < 0)
		ft_error(1);
	close (pipes[0]);
	ret = execve(cmd1.path, cmd1.arg, envp);
	if (ret == -1)
		ft_error(1);
}

void	parent(int f2, t_comm cmd2, int *pipes, char **envp)
{
	int	ret;

	if (dup2(pipes[0], STDIN_FILENO) < 0)
		ft_error(1);
	if (dup2(f2, STDOUT_FILENO) < 0)
		ft_error(1);
	close (pipes[1]);
	close (f2);
	ret = execve(cmd2.path, cmd2.arg, envp);
	if (ret == -1)
		ft_error(1);
}

void	pipex(int f1, t_comm cmd1, int f2, t_comm cmd2, char **envp)
{
	pid_t	sig;
	int		pipes[2];
	int		status;

	pipe (pipes);
	sig = fork();
	if (sig < 0)
		ft_error(1);
	else if (sig == 0)
		child(f1, cmd1, pipes, envp);
	else
	{
		waitpid(sig, &status, 0);
		parent(f2, cmd2, pipes, envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_comm	cmd1;
	t_comm	cmd2;
	int		f1;
	int		f2;
	char	**paths;

	if (argc < 5)
		return (0);
	if (test_file_acc(argv[1]) == -1)
		return (perror("Error"), 0);
	else
	{
		f1 = open(argv[1], O_RDONLY);
		f2 = open(argv[argc - 1], O_RDWR | O_CREAT, 0644);
		if (f1 == -1 || f2 == -1)
			ft_error(1);
	}
	paths = ft_split(ft_substr(envp[11], 5, ft_strlen(envp[11]) - 5), ':');
	cmd1 = parse_comms(argv[2], paths);
	cmd2 = parse_comms(argv[argc - 2], paths);
	//ft_free(paths);
	pipex(f1, cmd1, f2, cmd2, envp);
}

/*
https://reactive.so/post/42-a-comprehensive-guide-to-pipex
https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901 
*/