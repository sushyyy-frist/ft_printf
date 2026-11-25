/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ouc <sait-ouc@student.1337.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:36:25 by sait-ouc          #+#    #+#             */
/*   Updated: 2026/11/24 18:36:58 by sait-ouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(unsigned long c, int *len, int in_first)
{
	char	*hex;

	hex = "123456789abcdef";
	if(*len == -1)
		return;
	if (in_first)
		ft_putstr("0x", len);
	if (c < 16)
		ft_putchar(hex[c], len);
	else
	{
		ft_putptr(hex[c / 16], len, 0);
		if(*len == -1)
			return;
		ft_putchar(hex[c % 16], len);
	}
}
