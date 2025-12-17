/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafit <ayafit@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:19:43 by ayafit            #+#    #+#             */
/*   Updated: 2025/11/20 03:28:35 by ayafit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printlib.h"

static int	digit_count(unsigned int n)
{
	int				count;
	unsigned int	cpy;

	count = 0;
	if (n <= 9)
		return (1);
	cpy = n;
	while (cpy > 0)
	{
		cpy /= 10;
		count++;
	}
	return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int	l;

	l = digit_count(n);
	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10);
		ft_putnbr_unsigned(n % 10);
	}
	if (n < 10)
		ft_putchar(n + '0');
	return (l);
}
