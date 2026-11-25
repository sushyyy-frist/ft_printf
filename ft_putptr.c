/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ouc <sait-ouc@student.1337.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:36:25 by sait-ouc          #+#    #+#             */
/*   Updated: 2026/11/24 18:36:58 by sait-ouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(unsigned long c, int *len, int in_first)
{
	char	*hex;
	char	result[20];
	int		i;

	hex = "0123456789abcdef";
	i = 0;
	if (*len == -1)
		return ;
	if (in_first)
		ft_putstr("0x", len);
	if (c == 0)
		ft_putchar('0', len);
	while (c > 0)
	{
		result[i] = hex[c % 16];
		c = c / 16;
		i++;
	}
	while (i > 0 && *len != -1)
	{
		i--;
		ft_putchar(result[i], len);
	}
}
