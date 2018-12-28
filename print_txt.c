
#include "ft_printf.h"

int	print_c(t_flag flags, va_list ap)
{
	char	c;

	c = (char)va_arg(ap, int);
	ft_putchar(c);
	return (1);
}

int	print_s(t_flag flags, va_list ap)
{
	char	*str;
	char	*tmp1;
	char	*tmp2;
	int		len;

	str = va_arg(ap, char *);
	if (!(tmp1 = pre_str(str, flags)))
		return (-1);
	if (!(tmp2 = padd_str(tmp1, flags)))
		return (lib_diff(str, tmp1));
	ft_putstr(tmp2);
	len = ft_strlen(tmp2);
	lib_diff(str, tmp1);
	lib_diff(str, tmp2);
	return (len);
}

int	print_p(t_flag flags, va_list ap)
{
	char	*str;
	char	*tmp1;
	char	*tmp2;
	int		len;

	str = va_arg(ap, char *);
	if (!(tmp1 = ui_long_hex((long int)str, 0)))
		return (-1);
	if (!(tmp1 = pre_pxX(tmp1, flags)))
		return (-1);
	if (!(tmp2 = padd_pxX(tmp1, flags)))
		return (lib_diff(str, tmp1));
	ft_putstr(tmp2);
	len = ft_strlen(tmp2);
	lib_diff(str, tmp1);
	lib_diff(str, tmp2);
	return (len);
}
