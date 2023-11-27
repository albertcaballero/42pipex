/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:37:29 by albert            #+#    #+#             */
/*   Updated: 2023/11/27 11:52:49 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_file(int code, char *str)
{
	if (code == 403 || code == 402 || code == 126)
	{
		ft_putstr_fd("Pipex: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
	else if (code == 404)
	{
		ft_putstr_fd("Pipex: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
}

void	ft_error(int code, char *str)
{
	if (code == NOCOMMAND)
	{
		ft_putstr_fd("Pipex: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": Command not found\n", 2);
	}
	else if (code > 400 || code == NOXECUTE)
	{
		ft_error_file(code, str);
		if (code != 126)
			code = 1;
	}
	else if (str)
	{
		ft_putstr_fd("Pipex: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(code), 2);
	}
	else
		perror("Pipex");
	exit(code);
}