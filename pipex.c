/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albert <albert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:35:29 by albert            #+#    #+#             */
/*   Updated: 2023/09/08 18:12:53 by albert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int 	file1;
	char	*file1_text;
	
	if (argc <= 5)
		return (0);
	file1 = access(argv[1], F_OK);
	if (file1 < 0)
		return (strerror(errno));
}


/*
- open and read file 1 (argv[1])
	- if the file is not there throw error according to how it has to be
- identify AND execute cmd 1 (no freaking idea)
- identify AND execute to the existing output cmd 2 (no freaking idea)
- output to a temporary str
- create and write str to file 2 (argv[argc-1])
*/