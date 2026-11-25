/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-ouc <sait-ouc@student.1337.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 18:34:52 by sait-ouc          #+#    #+#             */
/*   Updated: 2026/11/24 18:34:59 by sait-ouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(char *str, ...);
void	perecentsign(va_list par, char c, int *len);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *str, int *len);
void	ft_putnbr(int n, int *len);
void	ft_putunsigned(int n, int *len);
void	ft_putptr(unsigned long c, int *len, int in_first);
void	ft_puthexa_lower(unsigned int c, int *len);
void	ft_puthexa_upper(unsigned int c, int *len);

#endif