/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convet.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 10:45:53 by amerrouc          #+#    #+#             */
/*   Updated: 2018/12/18 11:16:04 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		nb_base_len(long long int nb, int size_base)
{
	long long int	i;
	int				len;

	i = 1;
	len = 1;
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (i <= nb)
	{
		len++;
		i *= size_base;
	}
	return (len);
}

void	put_base(unsigned long int nb, char *str, const char *base)
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

char	*ui_long_hex(unsigned long int nb, int b)
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
