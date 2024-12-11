/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deabraha <deabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:41:50 by deabraha          #+#    #+#             */
/*   Updated: 2024/12/11 19:13:30 by deabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int	pars(const char *format, va_list ap)
{
	int count;
	
	count = 0;
	if(*format == 'c')
		count += putchar(va_arg(ap, int));
	return (count);
}	


int ft_printf(const char *format, ...)
{
	va_list	ap;
	int	count;
	
	va_start(ap, format);
	count = 0;
	while(*format)
	{
		if(*format == '%')
			{
				format++;
				count += pars(format, ap);
			}
		else
			count += putchar(*format);
		format++;
	}
	return (count);
}

int	main()
{
	ft_printf("olá %c\n Tudo bem?", 'a');
	ft_printf("olá %c\n Tudo bem?", 'a');
	ft_printf("olá %c\n Tudo bem?", 'a');
	ft_printf("olá %c\n Tudo bem?", 'a');
	ft_printf("olá %c\n Tudo bem?", 'a');
	ft_printf("olá %c\n Tudo bem?", 'a');
	ft_printf("olá %c\n Tudo bem?", 'a');
	ft_printf("olá %c\n Tudo bem?", 'a');
	
	return 0;
}