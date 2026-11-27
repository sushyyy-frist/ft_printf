/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ouc <sait-ouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:37:50 by sait-ouc          #+#    #+#             */
/*   Updated: 2026/11/27 17:20:27 by sait-ouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned(unsigned int n, int *len)
{
	char	result[20];
	int		i;

	i = 0;
	if (*len == -1)
		return ;
	if (n == 0)
	{
		ft_putchar('0', len);
		return ;
	}
	while (n > 0)
	{
		result[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	while (i > 0 && *len != -1)
	{
		i--;
		ft_putchar(result[i], len);
	}
}
