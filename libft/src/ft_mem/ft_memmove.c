/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 10:00:38 by jonascim          #+#    #+#             */
/*   Updated: 2022/10/31 09:44:26 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*auxdst;
	char	*auxsrc;

	if (dst == NULL && src == NULL)
		return (NULL);
	auxdst = (char *)dst;
	auxsrc = (char *)src;
	if (auxdst > auxsrc)
		while (len--)
			auxdst[len] = auxsrc[len];
	else
		while (len--)
			*(auxdst++) = *(auxsrc++);
	return (dst);
}
