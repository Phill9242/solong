/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phil <phil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 08:25:16 by phil              #+#    #+#             */
/*   Updated: 2022/01/14 08:25:38 by phil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*rtn;

	rtn = malloc(number * size);
	if (!rtn)
		return (NULL);
	ft_bzero (rtn, number * size);
	return (rtn);
}
