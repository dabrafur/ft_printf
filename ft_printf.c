/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deabraha <deabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:41:50 by deabraha          #+#    #+#             */
/*   Updated: 2024/12/12 15:42:46 by deabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pars(const char *format, va_list ap)
{
	int	count;

	count = 0;
	if (*format == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (*format == 's')
		count += ft_putstr(va_arg(ap, char*));
	return (count);
}	

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;

	va_start (ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += pars(format, ap);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	return (count);
}

int	main(void)
{
	ft_printf("olá %c Tudo bem?\n", 'D');
	ft_printf("olá %s Tudo bem?\n", "Débora");
	// ft_printf("olá %c\n Tudo bem?", 'a');
	// ft_printf("olá %c\n Tudo bem?", 'a');
	// ft_printf("olá %c\n Tudo bem?", 'a');
	// ft_printf("olá %c\n Tudo bem?", 'a');
	// ft_printf("olá %c\n Tudo bem?", 'a');
	// ft_printf("olá %c\n Tudo bem?", 'a');
	return (0);
}
