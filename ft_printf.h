/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deborafurlan <deborafurlan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:03:14 by deabraha          #+#    #+#             */
/*   Updated: 2024/12/15 23:27:30 by deborafurla      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int ft_putnbr(int nbr);
int ft_putunbr(unsigned int nbr);
int ft_puthex(unsigned long nbr);
int ft_putuphex(unsigned long nbr);
int	ft_putptr(unsigned long ptr);
int	ft_printf(const char *str, ...);

#endif
