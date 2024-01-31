/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:55:35 by alcaball          #+#    #+#             */
/*   Updated: 2023/11/27 10:08:59 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*arr;
	int		i;

	i = 0;
	arr = malloc (count * size);
	if (!arr)
		return (NULL);
	ft_bzero (arr, count * size);
	return (arr);
}
