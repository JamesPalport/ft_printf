/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_base.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 10:16:22 by amerrouc          #+#    #+#             */
/*   Updated: 2019/01/02 10:22:23 by amerrouc         ###   ########.fr       */
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

void	put_base(unsigned long long int nb, char *str, char *base)
{
	int	size_base;
	int	i;

	size_base = ft_strlen(base);
	if (nb >= size_base)
		put_base(nb / size_base, str, base);
	i = ft_strlen(str);
	str[i] = base[nb % size_base];
}
