/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:32:14 by joaonascime       #+#    #+#             */
/*   Updated: 2022/10/31 10:45:45 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int	i;

	if (*needle == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	while (*haystack != '\0' && len > 0)
	{
		i = 0;
		while (haystack[i] != '\0' && len - i > 0)
		{
			if (haystack[i] != needle[i])
				break ;
			if (needle[i + 1] == '\0')
				return ((char *)haystack);
			i++;
		}
		++haystack;
		--len;
	}
	return (NULL);
}
