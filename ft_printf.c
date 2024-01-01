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

static int	format_specifier(const char *format, va_list *args)
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
		c = va_arg(*args, int);
		len += write(1, &c, 1);
	}
	else if (*format == 's')
	{
		len += putstr(va_arg(*args, char *));
	}
	else if (*format == 'i' || *format == 'd')
	{
		len += putnbr((unsigned long)va_arg(*args, int));
	}
	else if (*format == 'u')
	{
		len += putnbr((unsigned long)va_arg(*args, unsigned int));
	}
	else if (*format == 'p')
	{
		len += print_pointer((unsigned long)va_arg(*args, void *));
	}
	else
		return(0);
	return(len);
}

int	ft_printf(const char *format, ...)
{
	va_list	*args;
	int		count;

	va_start(*args, format);

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
	va_end(*args);
	return(count);
}


#include <stdio.h>
#include <limits.h>
int main()
{
    // Example
	
	int number = 10;

	int *ptr = &number;

	// ft_printf("The value of the pointer M: %p\n", (void *)ptr);
	// printf("The value of the pointer O: %p\n", (void *)ptr);

	// ft_printf("The value of the pointer M: %p\n", NULL);
	// printf("The value of the pointer O: %p\n", NULL);




    //ft_printf("Hello, %s! You have %% apples.\n", "John");
	//printf("Hello, %s! You have %% apples.\n", "John");
	
	// ft_printf("%c, %c, %c\n", 'A', 'b', 'c');
	// ft_printf("%c for %s\n", 'E', "Effort");
	// printf("%c, %c, %c\n", 'A', 'b', 'c');
	// printf("%c for %s\n", 'E', "Effort");
	ft_printf("Number M: %d\n", INT_MIN);
	printf("Number O: %d\n", INT_MIN);
	ft_printf("Number M: %i\n", 000000);
	printf("Number O: %i\n", 000000);
	ft_printf("Number M: %u\n", 4294967);
	printf("Number O: %u\n", 4294967);
	// printf("%ld %ld", LONG_MIN, LONG_MAX);
	// printf("%d %d", INT_MIN, INT_MAX);
    return 0;
}