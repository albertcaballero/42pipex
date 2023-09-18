/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:36:06 by albert            #+#    #+#             */
/*   Updated: 2023/09/18 16:23:30 by alcaball         ###   ########.fr       */
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
	char	**path;
	char	**arg;
}	t_comm;

size_t	ft_strlen(const char *str);
int		ft_printf(const char *str, ...);
int		test_file_acc(char *f1, char *f2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
t_comm	parse_comms(char *c1, char **envp);


#endif