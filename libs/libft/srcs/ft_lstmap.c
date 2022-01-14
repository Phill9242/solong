/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phil <phil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 08:26:21 by phil              #+#    #+#             */
/*   Updated: 2022/01/14 08:27:20 by phil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;

	if (!lst)
		return (0);
	else
	{
		map = ft_lstnew(f(lst->content));
		if (!map)
		{
			ft_lstclear(&map, del);
			return (0);
		}
		map->next = ft_lstmap(lst->next, f, del);
		return (map);
	}
}
