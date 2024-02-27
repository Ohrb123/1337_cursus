/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:06:13 by oelharbi          #+#    #+#             */
/*   Updated: 2023/12/05 14:49:12 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_base(unsigned long s, int *count, int base, char format);
int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *str);
int		ft_putnbr(long s, int *count);

#endif