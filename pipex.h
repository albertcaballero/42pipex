/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:36:06 by albert            #+#    #+#             */
/*   Updated: 2023/09/26 15:11:16 by alcaball         ###   ########.fr       */
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

typedef struct s_commands
{
	char	*path;
	char	**arg;
}	t_comm;

size_t	ft_strlen(const char *str);
int		ft_printf(const char *str, ...);
int		test_file_acc(char *f1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
t_comm	parse_comms(char *c1, char **paths);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
void	ft_free(char **arr);
void	ft_error(int errcode);
void	ft_putnbr_fd(int n, int fd);

#endif