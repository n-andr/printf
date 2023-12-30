#include "ft_printf.h"

int	print_pointer(unsigned long address) 
{
	int		len;
	int		i;
	int		nibble;
	char	hex_char;

	len = 0;
	i = sizeof(unsigned long) * 2 -1;
	len += write(1, "0x", 2);
	while(i >= 0)
	{
		nibble = (address >> (i * 4)) & 0xF;
		if (nibble != 0) 
			break;
		i--;
	}
	while(i >= 0)
	{
		nibble = (address >> (i * 4)) & 0xF;
		if (nibble < 10) 
			hex_char = '0' + nibble;
		else
			hex_char = 'a' + nibble - 10;
		len += write(1, &hex_char, 1);
		i--;
	}
	return(len);
}