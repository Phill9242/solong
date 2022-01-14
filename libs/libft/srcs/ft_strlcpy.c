/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phil <phil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 08:26:47 by phil              #+#    #+#             */
/*   Updated: 2022/01/14 08:27:12 by phil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	count;

	count = -1;
	if (!dst_size)
		return (ft_strlen(src));
	while (dst_size-- && src[++count])
		dst[count] = src[count];
	dst[count] = 0;
	return (ft_strlen(src));
}
