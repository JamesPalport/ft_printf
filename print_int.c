/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 14:00:32 by amerrouc          #+#    #+#             */
/*   Updated: 2018/12/28 16:46:09 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int	print_di(t_flag flags, va_list ap)
{
	long long int	nbr;
	char			*tmp1;
	char			*tmp2;
	int				len;

	nbr = va_arg(ap, long long int);
	adj_size(&nbr, flags);
	if (!(tmp1 = lli_str(nbr, flags)))
		return (-1);
	if (!(tmp1 = pre_pxX(tmp1, flags)))
		return (-1);
	if (!(tmp2 = padd_str(tmp1, flags)))
		return (lib_diff(tmp2, tmp1));
	ft_putstr(tmp2);
	len = ft_strlen(tmp2);
	lib_diff(tmp1, tmp1);
	lib_diff(tmp2, tmp1);
	return (len);
}