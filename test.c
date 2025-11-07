/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsouza <jsouza@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:34:02 by jsouza            #+#    #+#             */
/*   Updated: 2025/11/07 14:40:11 by jsouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int ft_putnbr_base(int nbr, char *base)
{
    size_t base_len;
    long nb;
    int counter = 0;
    
    nb = nbr;
    base_len = ft_strlen(base);
    if (nb < 0)
    {
        if(base_len == 10)
            write(1, "-", 1);
        nb *= -1;
    }
    if ((size_t)nb >= base_len)
        counter = ft_putnbr_base(nb / base_len, base);
    write(1, &base[nb % base_len], 1);
    return (++counter);
}

int main ()
{
    int i = ft_putnbr_base(1234567890, "0123456789");

    printf("\n\n%d", i);
}