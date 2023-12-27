#include "ft_printf.h"

static int	putstr(char *str)
{	
	int	len;

	len = 0;
	if (str == NULL)
		len += write(1, "(null)", 6);
	while (*str)
	{
		write(1, str, 1);
		str++;
		len++;
	}
	return (len);
}

static int	format_specifier(const char *format, va_list args)
{
	int		len;
	char	c;

	len = 0;
	if (*format == '%')
	{
		len += write(1, "%", 1);
	}
	else if (*format == 'c')
	{
		c = va_arg(args, int);
		len += write(1, &c, 1);
	}
	else if (*format == 's')
	{
		len += putstr(va_arg(args, char *));
	}
	else if (*format == 'i' || *format == 'd')
	{
		len += ft_putnbr(va_arg(args, int));
	}
	else
		return(0);
	return(len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += format_specifier(format, args);
		}
		else
		{
			write(1, format, 1);
			count ++;
		}
		format++;
	}
	va_end(args);
	return(count);
}


#include <stdio.h>
int main()
{
    // Example
    //ft_printf("Hello, %s! You have %% apples.\n", "John");
	//printf("Hello, %s! You have %% apples.\n", "John");
	
	//ft_printf("%c, %c, %c\n", 'A', 'b', 'c');
	//printf("%c for %s\n", 'E', "Effort");
	ft_printf("Number: %d\n", 1234560000);
	printf("Number: %d\n", 1234560000);
	ft_printf("Number: %i\n", 000000);
	printf("Number: %i\n", 000000);
    return 0;
}