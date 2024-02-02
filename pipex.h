/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:36:06 by albert            #+#    #+#             */
/*   Updated: 2024/02/02 15:20:43 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include "src/libft/libft.h"

# define PERMOK 0
# define NOFILE 404
# define NOREAD 403
# define NOWRITE 402
# define NOXECUTE 126
# define NOCOMMAND 127

# define IN 1
# define OUT 2

typedef struct s_commands
{
	char	*path;
	char	**arg;
	char	*name;
	int		perm;
	int		id;
}	t_comm;

typedef struct s_fds
{
	int		fd;
	char	*name;
	int		perm;
}	t_fd;

typedef struct s_pipex
{
	int		cmdcont;
	char	**env;
	int		f_here;
	t_fd	fd[2];
}	t_pipex;

void	test_file_acc(char *f1);
t_comm	parse_comms(char *c1, char **paths);
void	ft_error(int errcode, char *str);
char	**check_path_var(char **envp);
void	ft_free_cmd(t_comm *cmds, int count);
int		check_cmd_permissions(char *cname);
int		check_file_permissions(char *fname);
int		write_heredoc(char *eof);
void	error_exit(t_comm cmd);
void	close_pipes_fds(int *pipes, t_pipex key);
void	duptemp(int *stdtmp, int flag);
void	*my_malloc(size_t size);
char	**ft_split_quotes(char *s);
char	**remove_quotes(char **splot);

#endif