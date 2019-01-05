/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 09:03:07 by amerrouc          #+#    #+#             */
/*   Updated: 2019/01/05 11:30:26 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_padd_char(char *padd, t_flag flags)
{
	padd[1] = '\0';
	padd[0] = ' ';
	if (flags.pad == '0' && (flags.conv == 's' || flags.conv == 'c'
				|| flags.pre == -1))
		padd[0] = '0';
}

void	apply_padd_str(char *out, const char *str, char *padd, t_flag flags)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 0;
	if (flags.pad == 0 || flags.pad == '0')
	{
		while (i++ < flags.min_len - len)
			ft_strlcat(out, padd, flags.min_len + 1);
		ft_strlcat(out, str, flags.min_len + 1);
	}
	else
	{
		ft_strcat(out, str);
		while (i++ < flags.min_len - len)
			ft_strlcat(out, padd, flags.min_len + 1);
	}
	if (!ft_isdigit(str[0]) && flags.conv != 's' && flags.conv != '%'
				&& !ft_strcmp("0", padd))
	{
		out[0] = str[0];
		out[i - 1] = '0';
	}
}

char	*padd_str(char const *str, t_flag flags)
{
	char	*out;
	int		len;
	char	padd[2];

	len = ft_strlen(str);
	if (flags.min_len == -1 || flags.min_len <= len)
		return ((char *)str);
	if ((out = ft_strnew(flags.min_len + 1)) == NULL)
		return (NULL);
	set_padd_char(padd, flags);
	apply_padd_str(out, str, padd, flags);
	return (out);
}

char	*padd_c(char c, t_flag flags)
{
	char	*out;
	int		len;
	char	padd[2];
	char	*str;

	if ((str = (char *)malloc(sizeof(char) * 2)) == NULL)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	len = 1;
	if (flags.min_len == -1 || flags.min_len <= 0)
		return ((char *)str);
	if ((out = ft_strnew(flags.min_len + 1)) == NULL)
		return (NULL);
	set_padd_char(padd, flags);
	apply_padd_str(out, str, padd, flags);
	return (out);
}

void	apply_padd_hex(char *out, char *str, char *padd,
		char *base, t_flag flags)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 0;
	if (flags.pad == 0 || flags.pad == '0')
	{
		if ((flags.conv == 'p' || flags.alt == 1) && padd[0] == '0')
			ft_strcat(out, base);
		if (flags.alt == 1 || flags.conv == 'p')
			flags.min_len -= ft_strlen(base);
		while (i++ < flags.min_len - len)
			ft_strcat(out, padd);
		if (padd[0] != '0' && (flags.conv == 'p' || flags.alt == 1))
			ft_strcat(out, base);
		ft_strcat(out, str);
	}
	else
	{
		if (flags.conv == 'p' || flags.alt == 1)
			ft_strcat(out, base);
		ft_strcat(out, str);
		if (flags.alt == 1 || flags.conv == 'p')
			flags.min_len -= ft_strlen(base);
		while (i++ < flags.min_len - len)
			ft_strcat(out, padd);
	}
}

char	*padd_hex(char *str, t_flag flags)
{
	char	*out;
	int		len;
	char	padd[2];
	char	*base;

	len = ft_strlen(str);
	if ((flags.min_len == -1 || flags.min_len <= len)
			&& (flags.conv != 'p' && flags.alt != 1))
		return (str);
	set_padd_char(padd, flags);
	if (flags.conv == 'X' && ft_strlen(str) != 0)
		base = "0X";
	else if ((flags.conv == 'x' && ft_strlen(str) != 0) || flags.conv == 'p')
		base = "0x";
	else if (flags.conv != 'x' && flags.conv != 'X')
		base = "0";
	else
		base = "";
	if (flags.conv != 'p'
			&& (ft_strlen(str) == 1 && str[0] == '0'))
		base = "";
	if (flags.min_len == -1 || flags.min_len <= len)
		flags.min_len = len + ft_strlen(base);
	if ((out = ft_strnew(flags.min_len + 1)) == NULL)
		return (0);
	apply_padd_hex(out, str,padd, base, flags);
	return (out);
}
