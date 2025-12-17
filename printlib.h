/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlib.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayafit <ayafit@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:51:47 by ayafit            #+#    #+#             */
/*   Updated: 2025/12/15 02:25:07 by ayafit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTLIB_H
# define PRINTLIB_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_puthex_low(unsigned int x);
int	ft_puthex_high(unsigned int x);
int	ft_putpointer(void *p);

#endif
