/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albert <albert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:36:06 by albert            #+#    #+#             */
/*   Updated: 2023/11/26 13:31:56 by albert           ###   ########.fr       */
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

# define NOFILE 404
# define NOREAD 403
# define NOWRITE 402
# define NOXECUTE 126
# define NOCOMMAND 127

typedef struct s_commands
{
	char	*path;
	char	**arg;
	char	*name;
	int		perm;
}	t_comm;

typedef struct s_fds
{
	int		fd;
	char	*name;
	int		perm;
}	t_fd;

typedef struct s_pipex
{
	int		argc;
	t_fd	fd[2];
}	t_pipex;

size_t	ft_strlen(const char *str);
int		ft_printf(const char *str, ...);
void	test_file_acc(char *f1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
t_comm	parse_comms(char *c1, char **paths);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
void	ft_error(int errcode, char *str);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	**check_path_var(char **envp);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_free_split(char **arr);
void	ft_free_cmd(t_comm *cmds);
void	check_cmd_permissions(t_comm *cmd);
void	check_file_permissions(t_fd *fd);

#endif