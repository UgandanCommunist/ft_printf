/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafit <ayafit@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 03:35:27 by ayafit            #+#    #+#             */
/*   Updated: 2025/12/15 02:25:31 by ayafit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlib.h"

static int	format_conversion(const char *format, va_list args)
{
	int	i;

	i = 0;
	if (format[i] == '%')
	{
		if (format[i + 1] == 'c')
			return (ft_putchar(va_arg(args, int)));
		else if (format[i + 1] == 's')
			return (ft_putstr(va_arg(args, char *)));
		else if (format[i + 1] == 'd' || format[i + 1] == 'i')
			return (ft_putnbr(va_arg(args, int)));
		else if (format[i + 1] == 'u')
			return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
		else if (format[i + 1] == 'x')
			return (ft_puthex_low(va_arg(args, unsigned int)));
		else if (format[i + 1] == 'X')
			return (ft_puthex_high(va_arg(args, unsigned int)));
		else if (format[i + 1] == 'p')
			return (ft_putpointer(va_arg(args, void *)));
		else if (format[i + 1] == '%')
			return (ft_putchar('%'));
		else
			return (-1);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		l;
	int		conv;
	va_list	args;

	l = 0;
	va_start(args, format);
	while (*format)
	{
		conv = format_conversion(format, args);
		if (conv == 0)
			l += ft_putchar(*format);
		else if (conv == -1)
			return (-1);
		else
		{
			l += conv;
			format++;
		}
		format++;
	}
	va_end(args);
	return (l);
}
