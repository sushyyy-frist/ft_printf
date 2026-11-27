/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ouc <sait-ouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 17:18:29 by sait-ouc          #+#    #+#             */
/*   Updated: 2026/11/27 18:03:34 by sait-ouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	perecentsign(va_list par, char c, int *len)
{
	if (c == 'c')
		ft_putchar(va_arg(par, int), len);
	else if (c == 's')
		ft_putstr(va_arg(par, char *), len);
	else if (c == 'i' || c == 'd')
		ft_putnbr(va_arg(par, int), len);
	else if (c == 'u')
		ft_putunsigned(va_arg(par, unsigned int), len);
	else if (c == 'p')
		ft_putptr((unsigned long)va_arg(par, void *), len, 1);
	else if (c == 'x')
		ft_puthexa_lower(va_arg(par, unsigned int), len);
	else if (c == 'X')
		ft_puthexa_upper(va_arg(par, unsigned int), len);
	else if (c == '%')
		ft_putchar('%', len);
}

static int	ft_check_format(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int	ft_handle_format(va_list par, const char *str, int *i, int *len)
{
	(*i)++;
	if (!str[*i] || !ft_check_format(str[*i]))
		return (-1);
	perecentsign(par, str[*i], len);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	par;

	if (!str)
		return (-1);
	i = 0;
	len = 0;
	va_start(par, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_handle_format(par, str, &i, &len) == -1)
				return (va_end(par), -1);
		}
		else
			ft_putchar(str[i], &len);
		i++;
	}
	va_end(par);
	return (len);
}
