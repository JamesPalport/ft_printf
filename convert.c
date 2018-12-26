/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 10:45:53 by amerrouc          #+#    #+#             */
/*   Updated: 2018/12/26 13:55:03 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

int		nb_base_len(unsigned long long int nb, int size_base)
{
	double	i;
	int		len;

	i = 1;
	len = 1;
	while (i < nb)
	{
		len++;
		i *= size_base;
	}
	return (len);
}

void	put_base(unsigned long long int nb, char *str, const char *base)
{
	int	size_base;
	int	i;

	size_base = ft_strlen(base);
	if (nb >= size_base)
		put_base(nb / size_base, str, base);
	i = ft_strlen(str);
	str[i] = base[nb % size_base];
}

char	*ui_hex(unsigned int nb, int b)
{
	char	*num;
	char	*base;

	if (b)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	num = ft_strnew(nb_base_len(nb, 16));
	put_base(nb, num, base);
	return (num);
}

char	*ui_long_hex(unsigned long long int nb, int b)
{
	char	*num;
	char	*base;

	if (b)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	num = ft_strnew(nb_base_len(nb, 16));
	put_base(nb, num, base);
	return (num);
}

char	*lli_str(long long int nb, t_flag flags)
{
	char	*num;
	char	*base;
	unsigned long long int nbr;
	int		len;

	base = "0123456789";
	nbr = (nb > 0) ? nb : -nb;
	len = nb_base_len(nbr, 10);
	num = ft_strnew(len + 1);
	if (nb < 0)
		num[0] = '-';
	else
	{
		if (flags.sign == 1)
			num[0] = ' ';
		else if (flags.sign == 2)
			num[0] = '+';
	}
	put_base(nbr, num, base);
	return (num);
}
