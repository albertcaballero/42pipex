/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:35:29 by albert            #+#    #+#             */
/*   Updated: 2024/01/25 13:43:12 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_pipex key, t_comm cmd, int *pipes)
{
	close (pipes[0]);
	error_exit(cmd);
	if (cmd.id == 0)
		dup2(key.fd[0].fd, STDIN_FILENO);
	if (cmd.id == key.cmdcont)
		dup2(key.fd[0].fd, STDOUT_FILENO);
	else
		dup2(pipes[1], STDOUT_FILENO);
	close (pipes[1]);
	if (execve(cmd.path, cmd.arg, key.env) < 0)
		exit(ft_error_msg(errno, cmd.arg[0]));
}

void	close_pipes_fds(int **pipes, t_pipex key)
{
	close(pipes[0]);
	close(pipes[1]);
	close(key.fd[0].fd);
	close(key.fd[1].fd);
}

void	duptemp(int *stdtmp, int flag)
{
	if (flag == IN)
	{
		stdtmp[0] = dup(STDIN_FILENO);
		stdtmp[1] = dup(STDOUT_FILENO);
	}
	if (flag == OUT)
	{
		dup2(stdtmp[0], STDIN_FILENO);
		dup2(stdtmp[1], STDOUT_FILENO);
		close(stdtmp[0]);
		close(stdtmp[1]);
	}
}

void	pipex(t_pipex key, t_comm *cmd)
{
	pid_t	*sig;
	int		pipes[2];
	int		stdtmp[2];
	int		status;
	int		i;

	i = 0;
	sig = malloc (sizeof(pid_t) * (key.cmdcont));
	duptemp(stdtmp, IN);
	while (i < key.cmdcont)
	{
		if (pipe(pipes) < 0)
			ft_error(errno, NULL);
		sig[i] = fork();
		if (sig[i] < 0)
			ft_error(errno, NULL);
		else if (sig[i] == 0)
			child(key.fd[0], cmd[i], pipes, key.env);
		dup2(pipes[0], STDIN_FILENO);
		close (pipes[1]);
		close (pipes[0]);
		i++;
	}
	i = 0;
	while (i < key.cmdcont)
		waitpid(sig[i++], &status, 0);
	free(sig);
	duptemp(stdtmp, OUT);
	close_pipes_fds(pipes, key);
	if (WIFEXITED(status))
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
	key.cmdcont = argc - 3;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		funct_here_doc(); //no existe aun :)
	key.fd[0].name = argv[1];
	key.fd[1].name = argv[argc - 1];
	key.fd[0].fd = open(key.fd[0].name, O_RDONLY);
	key.fd[1].fd = open(key.fd[1].name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	paths = check_path_var(envp);
	key.env = envp;
	i = 0;
	cmd = malloc(sizeof(*cmd) * (key.cmdcont));
	while (i < key.cmdcont)
	{
		cmd[i] = parse_comms(argv[i + 2], paths);
		cmd[i].id = i;
		i++;
	}
	ft_free_split(paths);
	pipex(key, cmd);
	i = 0;
	ft_free_cmd(cmd, key.cmdcont);
	exit(EXIT_SUCCESS);
}
