/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 09:03:07 by amerrouc          #+#    #+#             */
/*   Updated: 2018/12/26 09:03:35 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*padd_str(char *str, t_flag flags)
{
	char   *out;
	int     len;
	int     i;

	len = ft_strlen(str);
	if (flags.min_len == -1 || flags.min_len <= len)
		return (str);
	if ((out = ft_strnew(flags.min_len)) == NULL)
		return (0);
	i = 0;
	if (flags.pad == 0 || flags.pad == '0')
	{
		while (i++ < flags.min_len - len)
			ft_putchar(' ');
		ft_strcat(out, str);
	}
	else
	{
		ft_strcat(out, str);
		while (i++ < flags.min_len - len)
			ft_putchar(' ');
	}
	return (out);
}
