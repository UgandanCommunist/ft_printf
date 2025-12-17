/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafit <ayafit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 03:40:10 by ayafit            #+#    #+#             */
/*   Updated: 2025/11/24 01:24:36 by ayafit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlib.h"

static int	ft_revputstr(char *s)
{
	int	l;

	l = 0;
	while (*s)
		s++;
	s--;
	while (*s)
		l += ft_putchar(*(s--));
	return (l);
}

static int	ft_puthex(unsigned long x)
{
	int			l;
	char		*base;
	char		res[16];

	base = "0123456789abcdef";
	l = 0;
	while (x > 0)
	{
		res[l] = base[x % 16];
		l++;
		x /= 16;
	}
	res[l] = '\0';
	ft_revputstr(res);
	return (l);
}

int	ft_putpointer(void *p)
{
	int	l;

	l = 0;
	if (!p)
		return (ft_putstr("(nil)"));
	l += ft_putchar('0');
	l += ft_putchar('x');
	l += ft_puthex((unsigned long)p);
	return (l);
}
