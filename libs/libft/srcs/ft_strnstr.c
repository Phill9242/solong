/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phil <phil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 08:26:54 by phil              #+#    #+#             */
/*   Updated: 2022/01/14 08:27:10 by phil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	l;
	size_t	b;

	l = 0;
	b = 0;
	if (!*little)
		return ((char *)big);
	while (big[b + l] && little[l] && b + l < len)
	{
		while (big[b + l] == little[l] && big[b + l]
			&& little[l] && b + l < len)
		{
			if (!little[l + 1])
				return ((char *)&big[b]);
			l++;
		}
		l = 0;
		b++;
	}
	return (NULL);
}
