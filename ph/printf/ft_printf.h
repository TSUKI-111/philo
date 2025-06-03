/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayboudya <ayboudya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:12:48 by ayboudya          #+#    #+#             */
/*   Updated: 2024/12/20 17:47:52 by ayboudya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	format_specifier(char s, va_list arg, int count);
int	ft_printf(const char *string, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putunsnbr(unsigned int n);
int	ft_puthex(unsigned int n);
int	ft_putthex(unsigned int n);
int	ft_putp(void *p);
#endif
