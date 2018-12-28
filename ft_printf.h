/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:48:53 by amerrouc          #+#    #+#             */
/*   Updated: 2018/12/28 16:54:57 by amerrouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <limits.h>


typedef struct	s_flag
{
	int		alt;
	char	pad;
	int		sign;
	int		min_len;
	int		pre;
	char	mod[3];
	char	conv;
	int		err;
}				t_flag;
typedef int		(*t_fct)(t_flag, va_list);

char			*ui_hex(unsigned int nb, int b);
char			*ui_long_hex(unsigned long long int nb, int b);
t_flag			*set_flags(char *obj);
char			*pre_str(char *str, t_flag flags);
char			*pre_pxX(char *str, t_flag flags);
char			*padd_str(char *str, t_flag flags);
char			*lli_str(long long int nb, t_flag flags);
int				disp_str(char *str, int *count);
int				disp_arg(char *str, int *count, va_list ap, t_fct *functions);
t_fct			*init_functions(void);
int				chose_fct(t_flag *flags);
void			adj_size(long long int *nbr, t_flag flags);
int				len_flags(char *str, t_flag *flags);
int				print_c(t_flag flags, va_list ap);
int				print_s(t_flag flags, va_list ap);
int				print_p(t_flag flags, va_list ap);
int				print_di(t_flag flags, va_list ap);

char			*padd_pxX(char *str, t_flag flags);
int				lib_diff(char *str, char *tmp);
int				ft_printf(char *str, ...);


#endif
