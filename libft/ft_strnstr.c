/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:33:32 by alcaball          #+#    #+#             */
/*   Updated: 2023/05/30 17:11:16 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hayst, const char *need, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(need) == 0)
		return ((char *)hayst);
	while (hayst[i] != 0 && i < len)
	{
		j = 0;
		if (hayst[i] == need[j])
		{
			while (hayst[i + j] == need[j] && need[j] != '\0' && i + j < len)
			{
				if (need [j + 1] == '\0')
					return ((char *)&hayst[i]);
				j++;
			}
		}
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	char	hay[] = "lorem ipsum dolor sit amet dolork";
	char	need[] = "dolork";
	size_t len = 15;

	printf("1 is %s\n", ft_strnstr(hay, need, len));
	printf("2 is %s", strnstr(hay, need, len));
	return (0);
}
//*/