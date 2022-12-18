/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:10:24 by jonascim          #+#    #+#             */
/*   Updated: 2022/12/05 15:32:54 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin2(char const *s1, char const *s2)
{
	char	*strjoin;
	int		len;
	int		i;
	int		j;

	len = ft_strlen2(s1) + ft_strlen2(s2);
	strjoin = malloc(sizeof(char) * (len + 1));
	if (!strjoin || !s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		strjoin[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		strjoin[i] = s2[j];
		i++;
		j++;
	}
	strjoin[len] = 0;
	return (strjoin);
}

char	*ft_strchr2(const char *s, int c)
{
	char	*aux;

	aux = (char *)s;
	while (*aux != c && *aux != 0)
		aux++;
	if (*aux == c)
		return (aux);
	else
		return (NULL);
}

void	*ft_calloc2(size_t count, size_t size)
{
	char	*aux;

	aux = malloc(count * size);
	if (!aux)
		return (NULL);
	ft_bzero2(aux, count * size);
	return (aux);
}

void	ft_bzero2(void *s, size_t n)
{
	char	*aux;
	size_t	i;

	aux = (char *)s;
	i = 0;
	while (i < n)
		aux[i++] = '\0';
}

size_t	ft_strlen2(const char *str)
{
	size_t	aux;

	aux = 0;
	while (str[aux])
		aux++;
	return (aux);
}
