/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayboudya <ayboudya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:11:39 by ayboudya          #+#    #+#             */
/*   Updated: 2024/12/21 18:56:43 by ayboudya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	count = 0;
	while (s[i])
	{
		count += write(1, &s[i], 1);
		i++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int	c;

	c = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (n > 9)
	{
		c += ft_putnbr(n / 10);
		c += ft_putnbr(n % 10);
	}
	else if (n < 0)
	{
		c += ft_putchar('-');
		n *= -1;
		c += ft_putnbr(n);
	}
	else if (n >= 0 && n <= 9)
	{
		c += ft_putchar(n + '0');
	}
	return (c);
}

int	ft_putunsnbr(unsigned int n)
{
	int	c;

	c = 0;
	if (n > 9)
	{
		c += ft_putunsnbr(n / 10);
		c += ft_putunsnbr(n % 10);
	}
	else if (n <= 9)
		c += ft_putchar(n + '0');
	return (c);
}

int	ft_puthex(unsigned int n)
{
	int		c;
	char	*base;

	base = "0123456789abcdef";
	c = 0;
	if (n >= 16)
	{
		c += ft_puthex(n / 16);
		c += ft_puthex(n % 16);
	}
	else if (n < 16)
	{
		c += ft_putchar(base[n]);
	}
	return (c);
}
