/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:25:40 by alcaball          #+#    #+#             */
/*   Updated: 2023/10/24 11:36:54 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL || !str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}
/*
int	main(void)
{
	char	s[] = "      ";
	printf("%lu", ft_strlen(s));
	return (0);
} //*/