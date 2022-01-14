/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phil <phil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 08:26:59 by phil              #+#    #+#             */
/*   Updated: 2022/01/14 08:27:09 by phil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*rtn;
	size_t	lens;

	lens = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start > lens)
		rtn = (char *) malloc(sizeof(char));
	else if (lens <= len)
		rtn = (char *) malloc((lens - start + 1) * sizeof(char));
	else
		rtn = (char *) malloc((len + 1) * sizeof(char));
	if (!rtn)
		return (NULL);
	i = 0;
	while (len > i && start < lens)
		rtn[i++] = s[start++];
	rtn[i] = 0;
	return (rtn);
}
