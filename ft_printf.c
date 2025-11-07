/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsouza <jsouza@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:16:44 by jsouza            #+#    #+#             */
/*   Updated: 2025/11/07 16:24:03 by jsouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf.h"

int conversion(const char *s, va_list arg, int counter)
{
    if (s[0] == 'c')
        counter += ft_putchar_fd(va_arg(arg, char), 1);
    else if (s[0] == 's')
        counter += ft_putstr_fd(va_arg(arg, char *), 1);
    else if (s[0] == 'p')
    {
        counter += ft_putstr_fd("0x", 1);
        counter += ft_put_adrr(va_arg(arg, void *));
    }
    else if (s[0] == 'd' || s[0] == 'i')
        counter += ft_putnbr_base(va_arg(arg, int), "0123456789");
    else if (s[0] == 'u')
        counter += ft_putnbr_base(va_arg(arg, unsigned int), "0123456789");
    else if (s[0] == 'x')
        counter += ft_putnbr_base(va_arg(arg, int), "0123456789abcdef");
    else if (s[0] == 'X')
        counter += ft_putnbr_base(va_arg(arg, int), "0123456789ABCDEF");
    else if (s[0] == '%')
        counter += ft_putchar_fd('%', 1);
    else 
        return (-1);
    return(counter);
}

int ft_printf(const char *s, ...)
{
    va_list args;
    size_t i;
    int counter;

    counter = 0;
    i = 0;
    if (!s)
        return (-1);
    va_start(args, s);
    while(s)
    {
        if (s[i] == '%')
        {
            counter = conversion(&s[i + 1], args, counter);
            if (counter == -1)
                return (-1);
            i += 2;
        }
        ft_putchar_fd(s[i++], 1);
        counter++;
    }
    va_end(args);
    return(counter);
}
