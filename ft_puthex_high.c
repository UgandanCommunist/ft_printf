/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_high.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafit <ayafit@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 02:46:41 by ayafit            #+#    #+#             */
/*   Updated: 2025/11/24 01:05:05 by ayafit           ###   ########.fr       */
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

int	ft_puthex_high(unsigned int x)
{
	int			l;
	char		*base;
	char		res[8];

	if (x == 0)
		return (ft_putnbr(0));
	base = "0123456789ABCDEF";
	l = 0;
	while (x > 0)
	{
		res[l] = base[x % 16];
		l++;
		x /= 16;
	}
	ft_revputstr(res);
	return (l);
}
