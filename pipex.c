/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:35:29 by albert            #+#    #+#             */
/*   Updated: 2023/09/18 11:28:45 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	test_file_acc(char *f1, char *f2)
{
	int		file1;
	//char	*file1_text;

	ft_printf("%s %s", f1, f2);
	file1 = access(f1, F_OK);
	if (file1 < 0)
		return (-1);
	return (-1);
}

int	main(int argc, char **argv)
{
	if (argc <= 5)
		return (0);
	if (test_file_acc(argv[1], argv[argc - 1]) == -1)
		return (0);
}


/*
- open and read file 1 (argv[1])
	- if the file is not there throw error according to how it has to be
- identify AND execute cmd 1 (no freaking idea)
- identify AND execute to the existing output cmd 2 (no freaking idea)
- output to a temporary str
- create and write str to file 2 (argv[argc-1])
*/