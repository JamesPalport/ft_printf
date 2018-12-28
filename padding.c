/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 09:03:07 by amerrouc          #+#    #+#             */
/*   Updated: 2018/12/28 16:15:39 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*padd_str(char *str, t_flag flags)
{
	char   *out;
	int     len;
	int     i;
	char	*padd;

	len = ft_strlen(str);
	if (flags.min_len == -1 || flags.min_len <= len)
		return (str);
	if ((out = ft_strnew(flags.min_len)) == NULL)
		return (0);
	padd = " ";
	if (flags.pad == '0' && flags.conv == 's')
		padd = "0";
	i = 0;
	if (flags.pad == 0 || flags.pad == '0')
	{
		while (i++ < flags.min_len - len)
			ft_strcat(out, padd);
		ft_strcat(out, str);
	}
	else
	{
		ft_strcat(out, str);
		while (i++ < flags.min_len - len)
			ft_strcat(out, padd);
	}
	return (out);
}

char	*padd_pxX(char *str, t_flag flags)
{
	char	*out;
	int		len;
	int		i;
	char	*padd;
	char	*base;

	len = ft_strlen(str);
	if (flags.min_len == -1 || flags.min_len <= len)
		return (str);
	if ((out = ft_strnew(flags.min_len)) == NULL)
		return (0);
	padd = " ";
	if (flags.pad == '0')
		padd = "0";
	i = 0;
	if (flags.conv == 'X')
		base = "0X";
	else
		base = "0x";
	if (flags.pad == 0 || flags.pad == '0')
	{
		if (flags.pad == '0')
			ft_strcat(out, base);
		while (i++ < flags.min_len - len - 2)
			ft_strcat(out, padd);
		if (flags.pad != '0')
			ft_strcat(out, base);
		ft_strcat(out, str);
	}
	else
	{
		if (flags.conv == 'p')
			ft_strcat(out, base);
		ft_strcat(out, str);
		while (i++ < flags.min_len - len - 2)
			ft_strcat(out, padd);
	}
	return (out);
}
