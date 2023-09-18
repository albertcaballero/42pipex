/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:35:29 by albert            #+#    #+#             */
/*   Updated: 2023/09/18 13:39:53 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex()
{
	pid_t	sig;
	int 	pipes[2];

	pipe (pipes);
	sig = fork();
	if (sig < 0)
		return (-1);
	else if (sig == 0)
	{
		/*
		dup2()
		close end[0]
		execve(cmd1)
		*/
	}
	else
	{
		/*
		dup2()
		close end[1]
		execve(cmd2)
		*/
	}
	return 0;
}

int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
		return (0);
	// if (test_file_acc(argv[1], argv[argc - 1]) == -1)
	// 	return (0);
	parse_comms(argv[2], envp);
}

/*
- open and read file 1 (argv[1])
	- if the file is not there throw error according to how it has to be
- identify AND execute cmd 1 (no freaking idea)
- identify AND execute to the existing output cmd 2 (no freaking idea)
- output to a temporary str
- create and write str to file 2 (argv[argc-1])
https://reactive.so/post/42-a-comprehensive-guide-to-pipex
https://csnotes.medium.com/pipex-tutorial-42-project-4469f5dd5901 
*/