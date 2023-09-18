/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:44:17 by alcaball          #+#    #+#             */
/*   Updated: 2023/09/18 13:44:52 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	test_file_acc(char *f1, char *f2)
{
	if (access(f1, F_OK) < 0 || access(f2, F_OK))
		return (-1);
	return (0);
}

int	parse_comms(char *c1, char **envp)
{
	t_comm	cmd1;
	char	*path;
	char	**paths;
	char	**splitcomm;
	int		i;

	(void) c1;
	(void) cmd1;
	(void) splitcomm;
	//splitcomm = ft_split(c1, ' ');
	i = 0;
	path = ft_substr(envp[11], 5, ft_strlen(envp[11]) - 5);
	ft_printf(path);
	paths = ft_split(path, ':');
	return 0;
}
