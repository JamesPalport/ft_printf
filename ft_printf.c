/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 10:13:32 by amerrouc          #+#    #+#             */
/*   Updated: 2019/01/02 13:29:09 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;
	t_fct	*functions;
	int		ret;

	va_start(ap, str);
	functions = init_functions();
	i = 0;
	count = 0;
	while (str[i])
	{
		i = i + disp_str(str + i, &count);
		if (str[i] == '%')
		{
			if ((ret = disp_arg(str + i + 1, &count, ap, functions)) == -1)
				return (-1);
			i = i + 1 + ret;
		}
	}
	free(functions);
	va_end(ap);
	return (count);
}
