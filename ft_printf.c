/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 17:06:50 by anoukan           #+#    #+#             */
/*   Updated: 2024/08/08 17:06:52 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	return	write(1, &c, 1);
}

void	ft_putstr(char *s, int *count)
{
	int i = 0;

	if(!s)
	{
		ft_putstr("(null)", count);
		return;
	}
	while (s[i])
	{
		*count += ft_putchar(s[i]);
		i++;
	}
}

void	print_num(long long num, int base, int *count)
{
	char *hex = "0123456789abcdef";

	if (num == INT_MIN)
	{
		ft_putstr("-2147483648", count);
		return ;
	}
	if (num < 0)
		*count += ft_putchar('-');
	if (num >= base)
		print_num(num / base, base, count);
	*count += ft_putchar(hex[num % base]);
}

void	selector(va_list *ap, int *count, char flag)
{
	if (flag == 's')
		ft_putstr(va_arg(*ap, char *), count);
	else if (flag == 'd')
		print_num(va_arg(*ap, int), 10, count);
	else if (flag == 'x')
		print_num(va_arg(*ap, unsigned int), 16, count);
}

int	ft_printf(char *format, ...)
{
	int count = 0;
	int i = 0;
	va_list ap;

	va_start(ap, format);
	while(format[i])
	{
		if (format[i] == '%' && (format[i + 1] == 's' || format[i + 1] == 'd' ||format[i + 1] == 'x'))
		{
			selector(&ap, &count, format[i + 1]);
			i++;
		}
		else 
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return count;
}
