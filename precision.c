/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 09:04:10 by amerrouc          #+#    #+#             */
/*   Updated: 2018/12/26 09:04:25 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *pre_str(char *str, t_flag flags)
{
    char    *out;
    int     i;

    i = 0;
    if (flags.pre == -1)
        return (NULL);
    if ((out = ft_strnew(flags.pre)) == NULL)
        return (NULL);
    while (i < flags.pre)
    {
        out[i] = str[i];
        i++;
    }
    return (out);
}
