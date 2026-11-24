/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ouc <sait-ouc@student.1337.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:37:50 by sait-ouc          #+#    #+#             */
/*   Updated: 2026/11/24 18:37:51 by sait-ouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void	ft_putunsigned(int n, int *len)
{
	if(*len == -1)
		return;
	if (n <= 9)
		ft_putchar(n + '0', len);
	else
	{
		ft_putnbr(n / 10, len);
		ft_putchar(n % 10 + '0', len);
	}
}

// int main()
// {
//     int arr[]={1,2,3,4};
//     ft_putUnsigned(6, arr);
// }