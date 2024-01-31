/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:35:29 by albert            #+#    #+#             */
/*   Updated: 2024/01/25 17:34:12 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_pipex key, t_comm cmd, int *pipes)
{
	close (pipes[0]);
	error_exit(cmd);
	if (cmd.id == 0)
		dup2(key.fd[0].fd, STDIN_FILENO);
	if (cmd.id == key.cmdcont - 1)
		dup2(key.fd[1].fd, STDOUT_FILENO);
	else
		dup2(pipes[1], STDOUT_FILENO);
	close (pipes[1]);
	if (execve(cmd.path, cmd.arg, key.env) < 0)
		ft_error(errno, cmd.arg[0]);
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
			child_process(key, cmd[i], pipes);
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

void	init_files(t_pipex *key, char **argv)
{
	key->fd[0].name = argv[1];
	key->fd[1].name = argv[key->cmdcont + 2 + key->f_here];
	if (key->f_here)
	{
		key->fd[0].fd = write_heredoc(argv[2]);
		key->fd[1].fd = open(key->fd[1].name, O_RDWR | O_CREAT | O_APPEND, 0644);
		return ;
	}
	key->fd[0].fd = open(key->fd[0].name, O_RDONLY);
	key->fd[1].fd = open(key->fd[1].name, O_RDWR | O_CREAT | O_TRUNC, 0644);
}

int	main(int argc, char **argv, char **envp)
{
	t_comm	*cmd;
	t_pipex	key;
	char	**paths;
	int		i;

	if (argc < 4)
		return (write(2, "Pipex: Wrong Argument Count\n", 28), 1);
	key.f_here = (ft_strncmp(argv[1], "here_doc", 9) == 0);
	key.cmdcont = (argc - 3) - key.f_here;
	init_files(&key, argv);
	paths = check_path_var(envp);
	key.env = envp;
	cmd = malloc(sizeof(*cmd) * (key.cmdcont));
	if (!cmd)
		ft_error(errno, NULL);
	i = 0;
	while (i < key.cmdcont)
	{
		cmd[i] = parse_comms(argv[i + 2 + key.f_here], paths);
		cmd[i].id = i;
		i++;
	}
	free_split(paths);
	pipex(key, cmd);
	i = 0;
	ft_free_cmd(cmd, key.cmdcont);
	exit(EXIT_SUCCESS);
}
