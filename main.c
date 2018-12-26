#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"
#include <limits.h>

int		nb_arg(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			count++;
			while (str[i] && ft_isalpha(str[i]) == 0 && str[i] != '%')
				i++;
		}
		if (str[i] == '%' || str[i] == '\0')
			count--;
		if (str[i] && str[i] != '%')
			i++;
	}
	return (count);
}

int	disp_ez(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '%')
		ft_putchar(str[i++]);
	return (i);
}

void	put_ptr(void *ptr)
{
	long int	val;

	val = (long int)ptr;
	ft_putnbr(val);
}

void	test2(va_list ap)
{
	printf("%s\n", va_arg(ap, char *));
}


void	test(int nb, ...)
{

	char	*a;
	va_list	ap;

	va_start(ap, nb);
	while (nb--)
		test2(ap);
	va_end(ap);
}

int main(int	argc, char **argv)
{
	char *ptr;
	int	b;
	t_flag	*t;
	long long int	a;

//	ptr = "slt la mif";
//	printf("%p\n0x%s", ptr, ui_long_hex(ptr, 0));
//	b = 42949672950;
//	printf("%llx\n%s", ULLONG_MAX + 1, ui_long_hex(ULLONG_MAX + 1, 0));
	/*	test(3, "abc", "def", "fgh");*/
	/*printf("%d\n", nb_arg("%f"));
	disp_base("slt %d\n");
	printf("|\n");*/
/*	padding("test", "%d");*/
	t = set_flags(argv[1]);
//	printf("%s\n%10c", padd_str("t", *t), 't');
//	printf("%s\n%.3c", pre_str("test", *t), 't');
/*	b = 30000;
	ptr = "tet";*/
	/*printf("%llu\n", a);*/
/*	printf("test :%d\n", ft_isdigit('#'));
	printf("alt\t:%d\npad\t:\'%c\'\nsign\t:%d\n", t->alt, t->pad, t->sign);
	printf("min_len\t:%d\npre\t:%d\nconv\t:%c\n", t->min_len, t->pre, t->conv);
	printf("mod\t:%s\nerr\t:%d\n", t->mod, t->err);*/
	/*printf("%s\n%s\n%X", ui_hex(429496739, 1), ui_long_hex((unsigned int)429496739, 1), 429496739);*/
	printf("%30lld\n% .30lld\n",LLONG_MAX, LLONG_MAX);
	return 0;
}
