#include "ft_printf.h"

static int	putstr(char *str)
{	
	int	len;

	len = 0;
	if (str == NULL)
	{
		len += write(1, "(null)", 6);
		return(len);
	}
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
		len += write(1, "%", 1);
	else if (*format == 'c')
	{
		c = va_arg(*args, int);
		len += write(1, &c, 1);
	}
	else if (*format == 's')
		len += putstr(va_arg(*args, char *));
	else if (*format == 'i' || *format == 'd')
		len += putnbr((unsigned long)va_arg(*args, int));
	else if (*format == 'u')
		len += putnbr((unsigned long)va_arg(*args, unsigned int));
	else if (*format == 'p')
		len += print_pointer((unsigned long)va_arg(*args, void *));
	else if (*format == 'x')
		len += print_int_to_hex((unsigned int)va_arg(*args, int), 0);
	else if (*format == 'X')
		len += print_int_to_hex((unsigned int)va_arg(*args, int), 1);
	return(len);
}

int	ft_printf(const char *format, ...)
{
	va_list	*args;
	int		count;

	args = malloc(sizeof(va_list));
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
	free (args);
	return(count);
}

/*#include <stdio.h>
#include <limits.h>
int main()
{
    // Example
	
	int number = -250;

	int *ptr = &number;

	// ft_printf("The value of the pointer M: %p\n", (void *)ptr);
	// printf("The value of the pointer O: %p\n", (void *)ptr);

	// ft_printf("The value of the pointer M: %p\n", NULL);
	// printf("The value of the pointer O: %p\n", NULL);

    // ft_printf("M: Hello, %s! You have %i apples.\n", "John", number);
	// printf("O: Hello, %s! You have %i apples.\n", "John", number);
	
	// ft_printf("%c, %c, %c\n", 'A', 'b', 'c');
	// ft_printf("%c for %s\n", 'E', "Effort");
	// printf("%c, %c, %c\n", 'A', 'b', 'c');
	// printf("%c for %s\n", 'E', "Effort");
	// ft_printf("Number M: %d\n", INT_MIN);
	// printf("Number O: %d\n", INT_MIN);
	// ft_printf("Number M: %i\n", 000000);
	// printf("Number O: %i\n", 000000);
	// ft_printf("Number M: %u\n", 4294967);
	// printf("Number O: %u\n", 4294967);
	// ft_printf("Number M: %u\n", UINT_MAX);
	// printf("Number O: %u\n", UINT_MAX);
	// ft_printf("Number M: %u\n", INT_MAX);
	// printf("Number O: %u\n", INT_MAX);
	ft_printf("M: number %i in hex is %x\n", number, number);
	printf("O: number %i in hex is %x\n", number, number);
	//printf("O: number %i in hex is %X\n", number, number);
    return 0;
}*/