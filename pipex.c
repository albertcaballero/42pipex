/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:35:29 by albert            #+#    #+#             */
/*   Updated: 2023/09/18 16:51:51 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(int f1, t_comm cmd1, int *pipes)
{
	if (dup2(f1, STDIN_FILENO) < 0)
		exit(EXIT_FAILURE);
	if (dup2(pipes[1], STDOUT_FILENO))
		exit(EXIT_FAILURE);
	close (pipes[0]);
	execve(cmd1);
}

void	parent(int f2, t_comm cmd2, int *pipes)
{
	if (dup2(f2, STDOUT_FILENO) < 0)
		exit(EXIT_FAILURE);
	if (dup2(pipes[0], STDIN_FILENO))
		exit(EXIT_FAILURE);
	close (pipes[1]);
	close (f2);
	execve(cmd2);
}

int	pipex(int f1, t_comm cmd1, int f2, t_comm cmd2)
{
	pid_t	sig;
	int		pipes[2];
	int		status;

	pipe (pipes);
	sig = fork();
	if (sig < 0)
		return (-1);
	else if (sig == 0)
		child(f1, cmd1, pipes);
	else
	{
		waitpid(sig, &status, 0);
		parent(f2, cmd2, pipes);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_comm	cmd1;
	t_comm	cmd2;
	int		f1;
	int		f2;

	if (argc < 5)
		return (0);
	if (test_file_acc(argv[1], argv[argc - 1]) == -1)
		return (0);
	else
	{
		f1 = open(argv[1], O_RDONLY);
		f2 = open(argv[argc - 1], O_RDONLY);
	}
	cmd1 = parse_comms(argv[2], envp);
	cmd2 = parse_comms(argv[argc - 1], envp);
	pipex(f1, cmd1, f2, cmd2);
}

/*
https://reactive.so/post/42-a-comprehensive-guide-to-pipex
https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901 
*/