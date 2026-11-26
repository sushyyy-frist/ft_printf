/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ouc <sait-ouc@student.1337.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:34:19 by sait-ouc          #+#    #+#             */
/*   Updated: 2026/11/24 18:34:27 by sait-ouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	perecentsign(va_list par, char c, int *len)
{
	if (c && c == 'c')
		ft_putchar(va_arg(par, int), len);
	else if (c && c == 's')
		ft_putstr(va_arg(par, char *), len);
	else if (c && (c == 'i' || c == 'd'))
		ft_putnbr(va_arg(par, int), len);
	else if (c && c == 'u')
		ft_putunsigned(va_arg(par, unsigned int), len);
	else if (c && c == 'p')
		ft_putptr((unsigned long)va_arg(par, void *), len, 1);
	else if (c && c == 'x')
		ft_puthexa_lower(va_arg(par, unsigned int), len);
	else if (c && c == 'X')
		ft_puthexa_upper(va_arg(par, unsigned int), len);
	else if (c && c == '%')
		ft_putchar('%', len);
}

static int ft_check_format(char c)
{
	 if (c == 'c' || c == 's' || c == 'p' || c == 'd'
        || c == 'i' || c == 'u' || c == 'x' || c == 'X'
        || c == '%')
        return (1);
    return (0);
}



int	ft_printf(char *str, ...)
{
	int		i;
	int		len;

	if(!str) 
		return (-1);
	va_list	par;
	i = 0;
	len = 0;
	va_start(par, str);
	while (str[i] && len != -1)
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0' || !ft_check_format(str[i]))
			{
				return -1;
			}
			perecentsign(par, str[i], &len);
		}
		else
			ft_putchar(str[i], &len);
		i++;
	}
	va_end(par);
	return (len);
}
