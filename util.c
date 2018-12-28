/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 11:49:12 by amerrouc          #+#    #+#             */
/*   Updated: 2018/12/28 15:35:24 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lib_diff(char *str, char *tmp)
{
	if (tmp != str)
		free(tmp);
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
