#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int	ft_printf(const char *format, ...);
int	putnbr(long nb);
int	print_pointer(unsigned long address);
int	print_int_to_hex(int number, int upper);