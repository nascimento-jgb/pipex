/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 09:40:24 by jonascim          #+#    #+#             */
/*   Updated: 2022/10/31 13:48:03 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*auxdst;
	const char	*auxsrc;

	if (!dst && !src && n > 0)
		return (dst);
	auxdst = dst;
	auxsrc = src;
	while (n)
	{
		*auxdst++ = *auxsrc++;
		n--;
	}
	return (dst);
}
