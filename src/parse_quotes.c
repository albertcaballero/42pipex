/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:13:32 by alcaball          #+#    #+#             */
/*   Updated: 2024/02/02 15:22:00 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static size_t	ft_count_splits(char const *s)
{
	size_t	i;
	int		count;
	int		quot;

	i = 0;
	quot = 0;
	count = 0;
	if (s[0] && s[0] != 32)
		count++;
	while (s[i])
	{
		if (s[i] == '\'')
			quot++;
		if (quot % 2 == 0)
		{
			if (i > 0 && s[i] != 32 && s[i - 1] == 32)
				count++;
		}
		i++;
	}
	count += quot / 2;
	return (count);
}

size_t	ft_search_split(char const *s, size_t i)
{
	int	q;

	q = 0;
	while (s[i])
	{
		if (s[i] == '\'' && q == 0)
		{
			q = s[i];
			i++;
		}
		if (s[i] == q)
			q = 0;
		if (s[i] == 32 && q == 0)
			return (i);
		i++;
	}
	return (i);
}

char	**ft_split_quotes(char *s)
{
	int		m;
	int		i;
	int		j;
	char	**spl;

	m = 0;
	i = 0;
	j = 0;
	if (!s || ft_strlen(s) == 0)
		return (NULL);
	spl = my_malloc((ft_count_splits(s) + 1) * sizeof(char *));
	while (i <= (int)ft_strlen(s))
	{
		while (s[i] == ' ')
			i++;
		j = ft_search_split(s, i);
		spl[m] = ft_substr(s, i, j - i);
		if (!spl)
			return (free_split(spl));
		i = j + 1;
		m++;
	}
	spl[m] = NULL;
	spl = remove_quotes(spl);
	return (spl);
}

char	**remove_quotes(char **splot)
{
	int		i;
	char	**new;

	i = 0;
	new = my_malloc((ft_splitlen(splot) + 1) * sizeof(char *));
	while (splot[i])
	{
		new[i] = ft_strtrim(splot[i], "\'");
		i++;
	}
	new[i] = NULL;
	free_split(splot);
	return (new);
}
