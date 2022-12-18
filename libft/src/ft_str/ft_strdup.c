/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 15:35:25 by joaonascime       #+#    #+#             */
/*   Updated: 2022/10/31 18:12:28 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		lenght;
	char	*aux;

	lenght = ft_strlen(str);
	aux = (char *)malloc(sizeof(char) * (lenght + 1));
	if (!aux)
		return (NULL);
	lenght = 0;
	while (str[lenght])
	{
		aux[lenght] = str[lenght];
		lenght++;
	}
	aux[lenght] = '\0';
	return (aux);
}
