/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deborafurlan <deborafurlan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:41:50 by deabraha          #+#    #+#             */
/*   Updated: 2024/12/15 23:00:58 by deborafurla      ###   ########.fr       */
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
    else if (*format == 'd' || *format == 'i')
        count += ft_putnbr(va_arg(ap, int));
    else if (*format == 'u')
        count += ft_putunbr(va_arg(ap, unsigned int));
    else if (*format == 'x')
        count += ft_puthex(va_arg(ap, unsigned int));
    else if (*format == 'X')
        count += ft_putuphex(va_arg(ap, unsigned int));
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
		if (*format == '%' )
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
	ft_printf("olá %c Tudo bem?\n", 'D'); //UM UNICO CARACTERE
	ft_printf("olá %s Tudo bem?\n", "Débora"); // UMA STRING
	// ft_printf("olá %p Tudo bem?\n", 'a'); ponteiro void em hex
	ft_printf("olá %d Tudo bem?\n", 10); // numero decimal putnbr
	ft_printf("olá %i Tudo bem?\n", -1); //numero inteiro putnbr
	ft_printf("olá %u Tudo bem?\n", 20000); //(numero decimal (base 10) sem sinal)
	ft_printf("olá %x Tudo bem?\n", 20000); //Imprime um número em formato hexadecimal (base 16) em minúsculas
	ft_printf("olá %X Tudo bem?\n", 20000); //Imprime um número em formato hexadecimal (base 16) em maiúsculas
    // ft_printf("olá %% Tudo bem?\n", 'a'); putchar(%) imprime o sinal de porcentagem
	return (0);
}
