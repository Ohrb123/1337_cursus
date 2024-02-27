/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:37:07 by oelharbi          #+#    #+#             */
/*   Updated: 2023/12/01 16:40:34 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_base(unsigned long s, int *count, int base, char format)
{
	if (base == 16)
	{
		if (s / 16)
			ft_base((s / 16), count, base, format);
		if ((s % 16) <= 9)
			(*count) += ft_putchar((s % 16) + 48);
		else if ((s % 16) > 9 && format == 'x')
			(*count) += ft_putchar((s % 16) + ('a' - 10));
		else if ((s % 16) > 9 && format == 'X')
			(*count) += ft_putchar((s % 16) + ('A' - 10));
	}
	if (base == 10 && format == 'u')
	{
		if (s / 10)
			ft_base((s / 10), count, base, format);
		(*count) += ft_putchar((s % 10) + 48);
	}
	return (*count);
}

int	ft_putnbr(long s, int *count)
{
	if (s < 0)
	{
		(*count) += ft_putchar('-');
		s *= -1;
	}
	if (s / 10)
		ft_putnbr((s / 10), count);
	(*count) += ft_putchar((s % 10) + 48);
	return (*count);
}

int	ft_putstr(char *str)
{
	if (str == NULL)
		return (write (1, "(null)", 6));
	return (write (1, str, ft_strlen(str)));
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return (count);
}
