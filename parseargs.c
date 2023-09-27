/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:44:17 by alcaball          #+#    #+#             */
/*   Updated: 2023/09/27 14:01:06 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(int errcode, char	*str)
{
	if (errcode > 255)
		ft_printf("Bash: %s: command not found\n", str);
	else if (str)
		ft_printf("Bash: %s: %s\n", str, strerror(errcode));
	else
		perror("bash");
	exit(errcode);
}

void	ft_free(t_comm cmd)
{
	int	i;

	i = 0;
	free(cmd.path);
	while (cmd.arg[i])
	{
		free(cmd.arg[i]);
		i++;
	}
	free (cmd.arg);
}

void	test_file_acc(char *f1)
{
	if (access(f1, F_OK) < 0)
		ft_error (errno, f1);
}

t_comm	parse_comms(char *c1, char **paths)
{
	t_comm	cmd;
	int		i;
	char	*temp;

	i = 0;
	cmd.arg = ft_split(c1, ' ');
	while (paths[i] != NULL)
	{
		temp = ft_strjoin(paths[i], "/");
		cmd.path = ft_strjoin(temp, cmd.arg[0]);
		free (temp);
		if (access(cmd.path, X_OK) == 0)
		{
			free(paths[i]);
			return (cmd);
		}
		i++;
	}
	free(paths[i]);
	ft_error(256, cmd.arg[0]);
	ft_free(cmd); //no llega porque fterror hace exit
	return (cmd);
}
