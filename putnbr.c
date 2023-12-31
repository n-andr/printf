/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 13:50:03 by nandreev          #+#    #+#             */
/*   Updated: 2024/01/05 14:17:11 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_char(int n)
{
	char	ch;

	ch = n + '0';
	write (1, &ch, 1);
	return (1);
}

static int	conv_to_char(long nb)
{
	long	n;
	int		i;
	long	n2;
	int		len;

	n = nb;
	i = 1;
	len = 0;
	while (n > 9)
	{
		n = n / 10;
		i = i * 10;
	}
	n = nb;
	n2 = nb;
	while (i != 1)
	{
		n = n2 / i;
		len += write_char(n);
		n2 = n2 % i;
		i = i / 10;
	}
	len += write_char(n2);
	return (len);
}

int	putnbr(long nb)
{
	int	len;

	len = 0;
	if (nb >= 0)
		len += conv_to_char(nb);
	if (nb < 0)
	{
		len += write (1, "-", 1);
		len += conv_to_char(-nb);
	}
	return (len);
}
