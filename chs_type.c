/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chs_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 10:52:00 by amerrouc          #+#    #+#             */
/*   Updated: 2019/01/05 11:34:52 by amerrouc         ###   ########.fr       */
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
	if (c == 'o' || c == 'O')
		return (4);
	if (c == 'u' || c == 'U')
		return (5);
	if (c == 'x' || c == 'X')
		return (6);
	if (c == '%')
		return (8);
	if (c == '\0')
		return (-2);
	return (-1);
}

void			adj_size(long long int *nbr, t_flag flags)
{
	if (!ft_strcmp("ll", flags.mod))
		return ;
	else if (!ft_strcmp("l", flags.mod))
		*nbr = (long int)*nbr;
	else if (!ft_strcmp("h", flags.mod))
		*nbr = (short int)*nbr;
	else if (!ft_strcmp("hh", flags.mod))
		*nbr = (char)*nbr;
	else
		*nbr = (int)*nbr;
}

void			adj_uns_size(unsigned long long int *nbr, t_flag flags)
{
	if (!ft_strcmp("ll", flags.mod))
		return ;
	else if (!ft_strcmp("l", flags.mod))
		*nbr = (unsigned long int)*nbr;
	else if (!ft_strcmp("h", flags.mod))
		*nbr = (unsigned short int)*nbr;
	else if (!ft_strcmp("hh", flags.mod))
		*nbr = (unsigned char)*nbr;
	else
		*nbr = (unsigned int)*nbr;
}
