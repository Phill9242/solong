/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phil <phil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 08:26:35 by phil              #+#    #+#             */
/*   Updated: 2022/01/14 08:27:15 by phil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	number;

	if (n < 0)
	{
		ft_putchar_fd ('-', fd);
		number = -n;
	}
	else
		number = n;
	if (number > 9)
		ft_putnbr_fd (number / 10, fd);
	ft_putchar_fd (number % 10 + '0', fd);
}
