/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaball <alcaball@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:30:50 by alcaball          #+#    #+#             */
/*   Updated: 2024/01/15 14:18:18 by alcaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft.h"

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*freeall(char *s1, char *s2);

#endif