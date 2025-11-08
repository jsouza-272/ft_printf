/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsouza <jsouza@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:14:31 by jsouza            #+#    #+#             */
/*   Updated: 2025/11/07 14:07:54 by jsouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int ft_putnbr_base(int nbr, char *base, int counter)
{
    size_t base_len;
    long nb;

    nb = nbr;
    base_len = ft_strlen(base);
    if (nb < 0)
    {
        if(base_len == 10)
            write(1, "-", 1);
        nb *= -1;
    }
    if ((size_t)nb >= base_len)
        counter = ft_putnbr_base(nb / base_len, base, counter);
    write(1, &base[nb % base_len], 1);
    return (++counter);
}

int ft_put_adrr(void *nb, int counter)
{
    char *base;
    unsigned long *nbr;
    
    base = "0123456789abcdef";
    nbr = nb;
    if (*nbr >= 16)
        counter = ft_put_adrr((void *)(*nbr / 16), counter);
    write(1, &base[*nbr % 16], 1);
    return (++counter);
}
