/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 11:49:12 by amerrouc          #+#    #+#             */
/*   Updated: 2019/01/05 12:40:02 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lib_diff(char *str, char *tmp1, char *tmp2)
{
	if (tmp1 == tmp2)
	{
		if (tmp1 != str)
			free(tmp1);
	}
	else
	{
		if (tmp1 != str)
			free(tmp1);
		if (tmp2 != str)
			free(tmp2);
	}
	return (-1);
}

int	len_flags(char *str, t_flag *flags)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != flags->conv)
		i++;
	return (i + 1);
}

int	skip_spc(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}
