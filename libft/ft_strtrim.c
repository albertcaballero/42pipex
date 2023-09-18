/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:05:58 by alcaball          #+#    #+#             */
/*   Updated: 2023/05/30 17:11:45 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	valcheck(char a, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != 0)
	{
		if (set[i] == a)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	while (valcheck(s1[i], set) == 1)
		i++;
	if (i == (int)ft_strlen(s1) || s1[0] == 0)
	{
		s3 = ft_strdup("");
		return (s3);
	}
	if (set[0] == 0)
	{
		s3 = ft_strdup(s1);
		return (s3);
	}
	j = ft_strlen(s1) - 1;
	while (valcheck(s1[j], set) == 1)
		j--;
	s3 = ft_substr(s1, i, j - i + 1);
	if (!s3)
		return (NULL);
	return (s3);
}
/*
int	main(void)
{
	char	s1[] = "      ";
	char	set[] = " ";

	printf("%s", ft_strtrim(s1, set));
	return (0);
}//*/
