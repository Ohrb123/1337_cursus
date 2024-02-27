/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:49:29 by oelharbi          #+#    #+#             */
/*   Updated: 2023/12/05 14:45:48 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ft(const char *format, va_list ap, int count)
{
	format++;
	if (*format == '%')
		count += ft_putchar('%');
	else if (*format == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (*format == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (*format == 'x')
		count = ft_base((unsigned int)va_arg(ap, int), &count, 16, 'x');
	else if (*format == 'X')
		count = ft_base((unsigned int)va_arg(ap, int), &count, 16, 'X');
	else if (*format == 'p')
	{
		count += ft_putstr("0x");
		count = ft_base((long long)va_arg(ap, long long), &count, 16, 'x');
	}
	else if (*format == 'i' || *format == 'd')
		count = ft_putnbr(va_arg(ap, int), &count);
	else if (*format == 'u')
		count = ft_base((va_arg(ap, unsigned int)), &count, 10, 'u');
	else
		count += ft_putchar(*format);
	return (count);
}

static int	print_format(const char *format, va_list ap)
{
	int		count;

	count = 0;
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			count = ft_ft(format, ap, count);
			format++;
		}
		else if (*format != '%')
			count += ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;

	if (write(1, "", 0) == -1)
		return (-1);
	va_start(ap, format);
	return (print_format(format, ap));
}
