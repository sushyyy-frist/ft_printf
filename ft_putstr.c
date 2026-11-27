/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ouc <sait-ouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:37:30 by sait-ouc          #+#    #+#             */
/*   Updated: 2026/11/27 18:12:03 by sait-ouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *len)
{
	int	i;

	if (*len == -1)
		return ;
	if (!str)
		str = "(null)";
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i], len);
		i++;
	}
}
