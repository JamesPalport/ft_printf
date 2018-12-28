/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 09:04:10 by amerrouc          #+#    #+#             */
/*   Updated: 2018/12/28 16:21:06 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *pre_str(char *str, t_flag flags)
{
    char    *out;
    int     i;

    i = 0;
    if (flags.pre == -1)
        return (str);
    if ((out = ft_strnew(flags.pre)) == NULL)
        return (NULL);
    while (i < flags.pre)
    {
        out[i] = str[i];
        i++;
    }
    return (out);
}

char    *pre_pxX(char *str, t_flag flags)
{
    char    *out;
    int     i;
	int		len;

	len = ft_strlen(str);
	if (!ft_isdigit(str[0]))
		len--;
    i = 0;
    if (flags.pre == -1)
        return (str);
	if (flags.pre <= len)
		return (str);
	if ((out = ft_strnew(flags.pre)) == NULL)
        return (NULL);
    while (i < flags.pre - len)
    {
        out[i] = '0';
        i++;
    }
	if (!ft_isdigit(str[0]))
	{
		out[i] = '0';
		out[0] = str[0];
		ft_strcat(out, str + 1);
	}
	else
		ft_strcat(out, str);
	free(str);
    return (out);
}
