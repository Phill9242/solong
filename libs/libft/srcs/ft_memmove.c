/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phil <phil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 08:26:30 by phil              #+#    #+#             */
/*   Updated: 2022/01/14 08:27:17 by phil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src_pointer;
	unsigned char	*dst_pointer;

	if (!dst && !src)
		return (dst);
	src_pointer = (unsigned char *) src;
	dst_pointer = (unsigned char *) dst;
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	else
		while (len--)
			dst_pointer[len] = src_pointer[len];
	return (dst);
}
