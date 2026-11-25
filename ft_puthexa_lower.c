/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_lower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ouc <sait-ouc@student.1337.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 17:50:37 by sait-ouc          #+#    #+#             */
/*   Updated: 2026/11/24 18:35:33 by sait-ouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa_lower(unsigned int c, int *len)
{
	char	*hex;

	hex = "123456789abcdef";
	if(*len == -1)
		return;
	if (c < 16)
		ft_putchar(hex[c], len);
	else
	{
		ft_puthexa_lower(hex[c / 16], len);
		if(*len == -1)
			return;
		ft_putchar(hex[c % 16], len);
	}
}
