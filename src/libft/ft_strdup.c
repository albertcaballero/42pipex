/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:15:23 by alcaball          #+#    #+#             */
/*   Updated: 2023/11/27 10:21:07 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//duplicates a string
char	*ft_strdup(const char *s1)
{
	int		i;
	char	*arr;

	i = 0;
	arr = malloc (sizeof(char) * (ft_strlen(s1) + 1));
	if (!arr)
		return (NULL);
	while (s1[i] != '\0')
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = 0;
	return (arr);
}
