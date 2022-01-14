/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phil <phil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 08:26:29 by phil              #+#    #+#             */
/*   Updated: 2022/01/14 08:27:18 by phil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*pointer;
	unsigned char	*dst_pointer;

	if (!dst && !src)
		return (dst);
	pointer = (unsigned char *) src ;
	dst_pointer = (unsigned char *) dst;
	while (len--)
		*dst_pointer++ = *pointer++;
	return (dst);
}
