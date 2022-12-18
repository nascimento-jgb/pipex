/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:37:54 by jonascim          #+#    #+#             */
/*   Updated: 2022/11/01 15:48:19 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, const char limit)
{
	const char	*aux;
	int			counter;

	aux = str;
	counter = 0;
	while (*aux)
	{
		if (*aux != limit)
			if (aux == str || *(aux - 1) == limit)
				counter++;
		aux++;
	}
	return (counter);
}

static void	add_words(char **new, const char *str, char limit, int index)
{
	const char	*aux;
	const char	*start;

	aux = str;
	while (*aux)
	{
		if (*aux != limit)
		{
			if (aux == str || *(aux - 1) == limit)
			{
				start = aux;
				while (*aux && *aux != limit)
					aux++;
				if (count_words(aux, limit) > 0)
					add_words(new, aux, limit, index + 1);
				new[index] = (char *)malloc(aux - start + 1);
				if (new[index] != NULL)
					ft_strlcpy(new[index], start, aux - start + 1);
				return ;
			}
		}
		else
			aux++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	aux;

	if (s == NULL)
		return (NULL);
	aux = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * aux + 1);
	if (split == NULL)
		return (NULL);
	split[aux] = NULL;
	add_words(split, s, c, 0);
	return (split);
}
