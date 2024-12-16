/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deborafurlan <deborafurlan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:41:50 by deabraha          #+#    #+#             */
/*   Updated: 2024/12/16 09:17:52 by deborafurla      ###   ########.fr       */
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
    else if (*format == 'p')
        count += ft_putptr(va_arg(ap, unsigned long));
    else if (*format == 'x')
        count += ft_puthex(va_arg(ap, unsigned int));
    else if (*format == 'X')
        count += ft_putuphex(va_arg(ap, unsigned int));
    else if (*format == '%')
        count += ft_putchar('%');
    format ++;
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
    va_end(ap);
	return (count);
}

int	main(void)
{
	int a = 42;
    int *ptr = &a;
    
    
    ft_printf("caractere %ctudo  \n", 'D'); //UM UNICO CARACTERE
	ft_printf("string %s \n", "Débora"); // UMA STRING
	ft_printf("num decimal %d \n", 10); // numero decimal putnbr
	ft_printf("inteiro %i \n", -1); //numero inteiro putnbr
	ft_printf("decimal unsigned %u \n", 20000); //(numero decimal (base 10) sem sinal)
    ft_printf("ponteiro %p \n", (void*)ptr); //ponteiro void em hex
	ft_printf("hex %x \n", 20000); //Imprime um número em formato hexadecimal (base 16) em minúsculas
	ft_printf("hexupper %X \n", 20000); //Imprime um número em formato hexadecimal (base 16) em maiúsculas
    ft_printf("percentual %% \n", '%'); //putchar(%) imprime o sinal de porcentagem
	return (0);
}
