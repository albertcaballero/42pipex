/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:44:17 by alcaball          #+#    #+#             */
/*   Updated: 2023/09/19 17:25:57 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **arr)
{
	int	i;

	i = 0;
	while (arr)
	{
		free(arr[i]);
		i++;
	}
	free (arr);
}

int	test_file_acc(char *f1)
{
	if (access(f1, F_OK) < 0)
		return (-1);
	return (0);
}

t_comm	parse_comms(char *c1, char **paths)
{
	t_comm	cmd;
	int		i;

	i = 0;
	cmd.arg = ft_split(c1, ' ');
	while (paths[i] != NULL)
	{
		cmd.path = ft_strjoin(ft_strjoin(paths[i], "/"), cmd.arg[0]);
		if (access(cmd.path, F_OK) == 0)
			break ;
		else
			free(cmd.path);
		i++;
	}
	return (cmd);
}
