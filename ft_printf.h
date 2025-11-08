/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsouza <jsouza@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:15:34 by jsouza            #+#    #+#             */
/*   Updated: 2025/11/07 16:13:24 by jsouza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>

int ft_printf(const char *s, ...);
int ft_putnbr_base(int nbr, char * base);
int ft_put_adrr(unsigned long nbr);

#endif