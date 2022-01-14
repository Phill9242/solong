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
