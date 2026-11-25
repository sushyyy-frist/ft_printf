/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ouc <sait-ouc@student.1337.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:37:50 by sait-ouc          #+#    #+#             */
/*   Updated: 2026/11/24 18:37:51 by sait-ouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned(int n, int *len)
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
		result[i] = (c % 10) + '0';
		n = n / 10;
		i++;
	}
	while (i > 0 && *len != -1)
	{
		i--;
		ft_putchar(result[i], len);
	}
}

// int main()
// {
//     int arr[]={1,2,3,4};
//     ft_putUnsigned(6, arr);
// }