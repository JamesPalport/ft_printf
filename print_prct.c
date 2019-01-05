/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 09:26:44 by amerrouc          #+#    #+#             */
/*   Updated: 2019/01/05 09:28:47 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_prct(t_flag flags, va_list ap)
{
	char	*str;
	char	*tmp;
	int		len;

	str = "%";
	tmp = str;
	if (!(tmp = padd_str(tmp, flags)))
		return (lib_diff(str, tmp, tmp));
	ft_putstr(tmp);
	len = ft_strlen(tmp);
	lib_diff(str, tmp, tmp);
	return (len);
}
