/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 10:38:53 by amerrouc          #+#    #+#             */
/*   Updated: 2019/01/05 12:40:19 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	disp_str(char *str, int *count)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '%')
		ft_putchar(str[i++]);
	*count += i;
	return (i);
}

int	disp_arg(char *str, int *count, va_list ap, t_fct *functions)
{
	t_flag	*flags;
	int		ch;

	flags = set_flags(str);
	ch = chose_fct(flags);
	if (ch == -1 || ch == -2)
		return (skip_spc(str));
	*count += functions[ch](*flags, ap);
	return (len_flags(str, flags));
}
