#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
int main()
{
    // Example
	
	int number = -250;

	int *ptr = &number;

	ft_printf("The value of the pointer M: %p\n", (void *)ptr);
	printf("The value of the pointer O: %p\n", (void *)ptr);

	ft_printf("The value of the pointer M: %p\n", NULL);
	printf("The value of the pointer O: %p\n", NULL);

    ft_printf("M: Hello, %s! You have %i apples.\n", "John", number);
	printf("O: Hello, %s! You have %i apples.\n", "John", number);
	
	ft_printf("%c, %c, %c\n", 'A', 'b', 'c');
	ft_printf("%c for %s\n", 'E', "Effort");
	printf("%c, %c, %c\n", 'A', 'b', 'c');
	printf("%c for %s\n", 'E', "Effort");
	ft_printf("Number M: %d\n", INT_MIN);
	printf("Number O: %d\n", INT_MIN);
	ft_printf("Number M: %i\n", 000000);
	printf("Number O: %i\n", 000000);
	ft_printf("Number M: %u\n", 4294967);
	printf("Number O: %u\n", 4294967);
	ft_printf("Number M: %u\n", UINT_MAX);
	printf("Number O: %u\n", UINT_MAX);
	ft_printf("Number M: %u\n", INT_MAX);
	printf("Number O: %u\n", INT_MAX);
	ft_printf("M: number %i in hex is %x\n", number, number);
	printf("O: number %i in hex is %x\n", number, number);
	ft_printf("M: %s\n", (char *)NULL);
	printf("O: %s\n", (char *)NULL);
	ft_printf("M: !s%i<3!\%X%p+96}=%c)zGw]B_/4%XFt\n", 195254594, -845038997, (void *)-3601617074144709285, -2054390209, 108059203);
	printf("O: !s%i<3!\%X%p+96}=%c)zGw]B_/4%XFt\n", 195254594, -845038997, (void *)-3601617074144709285, -2054390209, 108059203);
    return 0;
}