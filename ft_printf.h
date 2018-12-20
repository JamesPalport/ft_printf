/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:48:53 by amerrouc          #+#    #+#             */
/*   Updated: 2018/12/20 11:07:08 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include "libft.h"

typedef struct	s_flag
{
	int		alt;
	char	pad;
	int		sign;
	int		min_len;
	int		pre;
	char	mod[2];
	char	conv;
	int		err;
}				t_flag;

char			*ui_hex(unsigned int nb, int b);
char			*ui_long_hex(unsigned long int nb, int b);
t_flag			*set_flags(char *obj);

#endif
