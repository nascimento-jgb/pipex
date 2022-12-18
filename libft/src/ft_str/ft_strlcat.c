/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:44:36 by joaonascime       #+#    #+#             */
/*   Updated: 2022/11/01 15:32:13 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	if (dstsize == 0)
		return ((size_t)ft_strlen(src));
	i = ft_strlen(dst);
	j = 0;
	if (dstsize < i)
	{
		j = ft_strlen(src);
		return (dstsize + j);
	}
	while (dstsize && i < (dstsize - 1) && src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	while (src[j])
	{
		i++;
		j++;
	}
	return (i);
}
