/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putHexaUpper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ouc <sait-ouc@student.1337.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:53:58 by sait-ouc          #+#    #+#             */
/*   Updated: 2026/11/24 16:53:59 by sait-ouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa_upper(unsigned int c, int *len)
{
	char	*hex;

	hex = "123456789ABCDE";
	if(*len == -1)
		return;
	if (c < 16)
		ft_putchar(hex[c], len);
	else
	{
		ft_puthexa_upper(hex[c / 16], len);
		if(*len == -1)
			return;
		ft_putchar(hex[c % 16], len);
	}
}
