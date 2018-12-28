/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chs_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 10:52:00 by amerrouc          #+#    #+#             */
/*   Updated: 2018/12/28 16:54:55 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				chose_fct(t_flag *flags)
{
	char	c;

	c = flags->conv;
	if (c == 'c')
		return (0);
	if (c == 's')
		return (1);
	if (c == 'p')
		return (2);
	if (c == 'd' || c == 'i')
		return (3);
	return (-1);
}

void			adj_size(long long int *nbr, t_flag flags)
{
	int			a;
	long int	b;
	short int	c;
	char		d;

	if (!ft_strcmp("l", flags.mod))
	{
		b = *nbr;
		*nbr = b;
	}
	else if (!ft_strcmp("ll", flags.mod))
		return ;
	else if (!ft_strcmp("h", flags.mod))
	{
		c = *nbr;
		*nbr = c;
	}
	else if (!ft_strcmp("hh", flags.mod))
	{
		d = *nbr;
		*nbr = d;
	}
	else
	{
		a = *nbr;
		*nbr = a;
	}
}
