#include "ft_printf.h"

int ft_putuphex(unsigned long nbr)
{
     int    count;
     char   *hex;
    
    count = 0;
    hex = "0123456789ABCDEF";
    if (nbr >= 16)
        count += ft_putuphex(nbr / 16);
    count += write(1, &hex[nbr % 16], 1);
    return (count);
}