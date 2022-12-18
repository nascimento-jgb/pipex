/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:29:15 by joaonascime       #+#    #+#             */
/*   Updated: 2022/10/31 15:48:22 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = (ft_strlen(s) + 1);
	while (*s)
		s++;
	while (len > 0)
	{
		if (*s == c)
			return ((char *)s);
		len--;
		s--;
	}
	return (NULL);
}
