/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 09:40:24 by amerrouc          #+#    #+#             */
/*   Updated: 2019/01/02 14:02:02 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	*new_flags(void)
{
	t_flag	*new;

	if ((new= (t_flag *)malloc(sizeof(t_flag))) == 0)
		return ((t_flag *)0);
	new->alt = 0;
	new->pad = 0;
	new->sign = 0;
	new->min_len = -1;
	new->pre = -1;
	new->mod[0] = 0;
	new->mod[1] = 0;
	new->mod[2] = 0;
	new->conv = 0;
	new->err = 0;
	return (new);
}

t_flag	*set_flags(char *obj)
{
	t_flag	*new;
	int		i;

	new = new_flags();
	i = 0;
	while (obj[i] && new->err == 0 && new->conv == 0)
	{
		if (obj[i] == '.' && new->pre == -1)
		{
			i++;
			new->pre = ft_atoi(obj + i);
			while (ft_isdigit(obj[i + 1]))
				i++;
		}
		if (ft_isdigit(obj[i]) && obj[i] != '0' && new->pre == -1)
		{
			if (new->min_len == -1)
				new->min_len = ft_atoi(obj + i);
			while (ft_isdigit(obj[i + 1]))
				i++;
		}
		if (new->min_len == -1 && new->pre == -1)
		{
			if (obj[i] == '#')
				new->alt = 1;
			if (obj[i] == '+')
				new->sign = 2;
			if (obj[i] == ' ' && new->sign != 2)
				new->sign = 1;
			if (obj[i] == '0' && new->pad == 0)
				new->pad = '0';
			if (obj[i] == '-')
				new->pad = ' ';
		}
		else if (obj[i] == '#' || obj[i] == '+'
				|| obj[i] == ' ' || obj[i] == '-' || obj[i] == '%')
			new->err = 1;
		if (ft_isalpha(obj[i]))
		{
			if (obj[i] == 'l' || obj[i] == 'h' || obj[i] == 'L')
			{
				if (new->mod[0] == 0)
					new->mod[0] = obj[i];
				else if (new->mod[0] == obj[i] && new->mod[1] == 0)
					new->mod[1] = obj[i];
				else
					new->err = 1;
				if (new->err)
					new->conv = obj[++i];
			}
			else
				new->conv = obj[i];
		}
		i++;
	}
/*	if (new->pre != -1)
		new->pre++;
	if (new->min_len != -1)
		new->min_len++;*/
	return (new);
}
