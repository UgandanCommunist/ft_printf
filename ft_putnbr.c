/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafit <ayafit@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:19:43 by ayafit            #+#    #+#             */
/*   Updated: 2025/11/19 19:50:38 by ayafit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlib.h"

static int	digit_count(int n)
{
	int	count;
	int	cpy;

	count = 0;
	if (n >= 0 && n <= 9)
		return (1);
	cpy = n;
	if (cpy < 0)
	{
		cpy *= -1;
		count++;
	}
	while (cpy > 0)
	{
		cpy /= 10;
		count++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int	l;

	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	l = digit_count(n);
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + '0');
	return (l);
}
