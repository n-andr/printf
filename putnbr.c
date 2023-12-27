#include "ft_printf.h"

static int	write_char(int n)
{
	char	ch;

	ch = n + '0';
	write (1, &ch, 1);
	return (1);
}

static int	conv_to_char(int nb)
{
	int	n;
	int	i;
	int	n2;
	int len;

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

int	ft_putnbr(int nb)
{
	int	len;

	len = 0;
	if (nb >= 0)
		len += conv_to_char(nb);
	if (nb == -2147483648)
		len += write (1, "-2147483648", 11);
	if (nb < 0 && nb != -2147483648)
	{
		len += write (1, "-", 1);
		len += conv_to_char(-nb);
	}
	return (len);
}