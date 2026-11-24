/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ouc <sait-ouc@student.1337.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:34:19 by sait-ouc          #+#    #+#             */
/*   Updated: 2026/11/24 18:34:27 by sait-ouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	perecentsign(va_list par, char c, int *len)
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

int	ft_printf(char *str, ...)
{
	int		i;
	int		len;
	va_list	par;

	i = 0;
	len = 0;
	va_start(par, str);
	while (str[i] && len != -1)
	{
		if (str[i] == '%')
		{
			i++;
			perecentsign(par, str[i], &len);
		}
		else
			ft_putchar(str[i], &len);
		i++;
	}
	va_end(par);
	return (len);
}

// #include <stdio.h>
// int main()
// {
// ft_printf("\n");
// ft_printf("Hello World\n");
// ft_printf("100%%\n");
// ft_printf("%%\n");
// ft_printf("%%%%\n");
// ft_printf("%%%%%%\n");
// ft_printf("Hello %% World\n");
// ft_printf("42%% is the answer\n");

// ft_printf("%c", 'A');
// ft_printf("%c", 'z');
// ft_printf("%c", '0');
// ft_printf("%c", ' ');
// ft_printf("%c", '\n');
// ft_printf("%c", '\t');
// ft_printf("%c", '\0');
// ft_printf("%c", 127);
// ft_printf("%c", 0);
//  int result;

// result = ft_printf("Hello");
// printf("\nReturned length: %d\n", result);
//     // return (0);
// int main(){

//     ft_printf("hello      %        sworld","5555");
//     printf("\nhello      %        sworld","5555");
// }