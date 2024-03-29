/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:46:52 by alcaball          #+#    #+#             */
/*   Updated: 2024/01/15 18:06:18 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cntlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != 0)
		i++;
	return (i);
}

static int	cntwrd(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	if (s[i] == 0)
		return (0);
	while (s[i] == c)
	{
		i++;
		if (s[i] == 0)
			return (0);
	}
	while (s[i] != 0)
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
			count++;
		i++;
	}
	return (count);
}

static char	*rmchar(char *s, char c, int a)
{
	int	j;

	j = 0;
	while (s[j] == c && a == 1 && s[j] != 0)
	{
		j++;
		if (s[j] != c)
			return (&s[j]);
	}
	while (!(s[j] == c && s[j + 1] != c) && s[j + 1] != 0)
		j++;
	j++;
	return (&s[j]);
}

void	*free_split(char **spl)
{
	int	i;

	i = 0;
	if (!spl)
		return (NULL);
	while (spl[i])
	{
		free(spl[i]);
		i++;
	}
	free (spl);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		m;
	int		count;
	char	**spl;

	m = 0;
	if (!s || ft_strlen(s) == 0)
		return (NULL);
	count = cntwrd (s, c);
	spl = (char **) malloc ((count + 1) * sizeof(char *));
	if (!spl)
		return (NULL);
	if (s[0] == c)
		s = rmchar ((char *) s, c, 1);
	while (m < count)
	{
		spl[m] = ft_substr (s, 0, cntlen(s, c));
		if (!spl)
			return (free_split(spl));
		s = rmchar ((char *) s, c, 2);
		m++;
	}
	spl[m] = NULL;
	return (spl);
}
