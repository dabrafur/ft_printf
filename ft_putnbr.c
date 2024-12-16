#include "ft_printf.h"

int ft_putnbr(int nbr)
{
    long    num;
    int     count;

    num = nbr;
    count = 0;

    if (num < 0)
    {
        count += ft_putchar('-');
        num = -num;
    }
    if (num >= 10)
        count += ft_putnbr(num / 10);
    count += ft_putchar((num % 10) + '0');
    return (count);
}
