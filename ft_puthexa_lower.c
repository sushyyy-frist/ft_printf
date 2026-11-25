/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_lower.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ouc <sait-ouc@student.1337.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 17:50:37 by sait-ouc          #+#    #+#             */
/*   Updated: 2026/11/24 18:35:33 by sait-ouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa_lower(unsigned int c, int *len)
{
	char	*hex;
	char	result[20];
	int		i;

	hex = "0123456789abcdef";
	i = 0;
	if (*len == -1)
		return ;
	if (c == 0)
	{
		ft_putchar('0', len);
		return ;
	}
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
