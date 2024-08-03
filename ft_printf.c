#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *s, int *count)
{
    int i = 0;

    while (s[i])
    {
        ft_putchar(s[i]);
        i++;
    }
    *count += i - 1;
}

void print_num(long long int num, int base, int *count)
{
	char *hexa = "0123456789abcdef";


    printf("%lld\n%d\n", num, base);
    if (num == -2147483648)
        ft_putstr("-2147483648", count);
	if (num < 0)
	{
		num *= -1;
		*count += 1; 
        ft_putchar('-');
	}
	if (num >= base)
		print_num((num / base), base, count);
    *count +=1;
    ft_putchar(hexa[num % base]);
	return ;
}

void flag(int *count, char c, va_list ap)
{
    if (c == 's')
        ft_putstr(va_arg(ap, char *), count);
    else if (c == 'd')
        print_num(va_arg(ap, int), 10, count);
    else if (c == 'x')
        print_num(va_arg(ap, unsigned int ), 16, count);
}


int ft_printf(const char *format, ... )
{
    int count = 0;
    int i = 0;
    va_list ap;

    va_start(ap, format);
    while (format[i])
    {
        if (format[i] == '%' && (format[i + 1] == 's' || format[i + 1] == 'd' || format[i + 1] == 'x'))
        {
            flag(&count, format[i + 1], ap);
            i++;
        }
        else
        {
            count++;
            ft_putchar(format[i]);
        }
        i++;
    }
    va_end(ap);
    return count;
}

int main(void)
{
    ft_printf("%s\n%d\n%x\n", "hoolall adlkfl asdf", -2147483648, 15);
    printf("%s\n%ld\n%x\n", "hoolall adlkfl asdf", -2147483648, 15);
    return 0;
}
