/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phil <phil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 08:26:42 by phil              #+#    #+#             */
/*   Updated: 2022/01/14 08:27:13 by phil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*cpy;
	int		len;

	len = ft_strlen(str);
	cpy = malloc (len + 1);
	if (!str || !cpy)
		return (NULL);
	ft_memcpy(cpy, str, len);
	cpy[len] = 0;
	return (cpy);
}
