/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 10:45:53 by amerrouc          #+#    #+#             */
/*   Updated: 2019/01/05 11:05:18 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ui_long_hex(unsigned long long int nb, int b)
{
	char	*num;
	char	*base;

	if (b)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	num = ft_strnew(nb_base_len(nb, 16) + 1);
	put_base(nb, num, base);
	return (num);
}

char	*ui_long_oct(unsigned long long int nb)
{
	char	*num;
	char	*base;

	base = "01234567";
	num = ft_strnew(nb_base_len(nb, 16) + 1);
	put_base(nb, num, base);
	return (num);
}

char	*lli_str(long long int nb, t_flag flags)
{
	char					*num;
	char					*base;
	unsigned long long int	nbr;
	int						len;

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

char	*ulli_str(unsigned long long int nbr)
{
	char	*num;
	char	*base;
	int		len;

	base = "0123456789";
	len = nb_base_len(nbr, 10);
	num = ft_strnew(len + 1);
	put_base(nbr, num, base);
	return (num);
}
