/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayboudya <ayboudya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:11:32 by ayboudya          #+#    #+#             */
/*   Updated: 2024/12/20 17:56:09 by ayboudya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putthex(unsigned int n)
{
	int		c;
	char	*base;

	base = "0123456789ABCDEF";
	c = 0;
	if (n >= 16)
	{
		c += ft_putthex(n / 16);
		c += ft_putthex(n % 16);
	}
	else if (n < 16)
	{
		c += ft_putchar(base[n]);
	}
	return (c);
}

static int	ft_puthex2(unsigned long int n)
{
	int		c;
	char	*base;

	base = "0123456789abcdef";
	c = 0;
	if (n >= 16)
	{
		c += ft_puthex2(n / 16);
		c += ft_puthex2(n % 16);
	}
	else if (n < 16)
	{
		c += ft_putchar(base[n]);
	}
	return (c);
}

int	ft_putp(void *p)
{
	int					c;
	unsigned long int	n;

	if (!p)
		return (write(1, "(nil)", 5));
	n = (unsigned long int)p;
	c = 0;
	c += ft_putstr("0x");
	c += ft_puthex2(n);
	return (c);
}
