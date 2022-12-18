/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonascim <jonascim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:59:47 by jonascim          #+#    #+#             */
/*   Updated: 2022/11/16 11:13:44 by jonascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list	*new;
	t_list	*res;

	if (f == NULL || del == NULL)
		return (NULL);
	res = NULL;
	while (lst)
	{
		new = ft_lstnew(f((*lst).content));
		if (new == NULL)
		{
			ft_lstclear(&res, del);
			break ;
		}
		ft_lstadd_back(&res, new);
		lst = (*lst).next;
	}
	return (res);
}
