/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:29:05 by jonascim          #+#    #+#             */
/*   Updated: 2022/11/01 15:33:37 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start,
size_t len)
{
	char	*substr;
	size_t	len1;
	size_t	len2;

	if (s == NULL)
		return (NULL);
	len1 = ft_strlen(s);
	if (len1 < (size_t) start)
		return (ft_strdup("\0"));
	len2 = len1 - start;
	if (len2 > start)
		len2 = len;
	substr = (char *)malloc((sizeof(char)) * len + 1);
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, len2 + 1);
	return (substr);
}
