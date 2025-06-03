/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayboudya <ayboudya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:11:19 by ayboudya          #+#    #+#             */
/*   Updated: 2024/12/20 18:01:34 by ayboudya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_specifier(char s, va_list arg, int count)
{
	if (s == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (s == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (s == 'p')
		count += ft_putp(va_arg(arg, void *));
	else if (s == 'd' || s == 'i')
		count += ft_putnbr(va_arg(arg, int));
	else if (s == 'u')
		count += ft_putunsnbr(va_arg(arg, unsigned int));
	else if (s == 'x')
		count += ft_puthex(va_arg(arg, unsigned long int));
	else if (s == 'X')
		count += ft_putthex(va_arg(arg, unsigned long int));
	else if (s == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(args, string);
	if (!string)
		return (-1);
	while (string[i])
	{
		if (string[i] != '%')
			count += ft_putchar(string[i]);
		else if (string[i] == '%')
		{
			i++;
			if (string[i] == '\0')
				return (-1);
			count = format_specifier(string[i], args, count);
		}
		i++;
	}
	va_end(args);
	return (count);
}
// #include <stdio.h>
// int main()
// {
// 	char *str= NULL;
// 	ft_printf(" NULL %s NULL \n", str);
// 	printf(" NULL %s NULL \n", str);
// }