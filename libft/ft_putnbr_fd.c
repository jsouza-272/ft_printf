/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsouza <jsouza@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:31:41 by jsouza            #+#    #+#             */
/*   Updated: 2025/11/07 14:40:37 by jsouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	s;
	int counter;

	nb = n;
	counter = 0;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
		counter += ft_putnbr_fd(nb / 10, fd);
	nb = nb % 10;
	s = nb + '0';
	write(fd, &s, 1);
	return (counter);
}
