/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:06:16 by jonascim          #+#    #+#             */
/*   Updated: 2022/11/07 16:47:44 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;
	const char	*end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = s1;
	end = s1 + ft_strlen(s1);
	while (ft_strchr(set, *start))
		++start;
	while (ft_strchr(set, *end))
		--end;
	return (ft_substr(s1, start - s1, end - start + 1));
}
