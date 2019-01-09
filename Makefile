# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 16:50:34 by amerrouc          #+#    #+#              #
#    Updated: 2019/01/09 13:20:02 by amerrouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = chs_type.c convert.c disp.c flags.c ft_printf.c functions.c nbr_base.c \
	  padding.c pre.c print_int.c print_txt.c print_uint.c util.c print_prct.c\
	  print_dec.c apply_padd.c set_pb.c\
	  Libft/ft_strnew.c Libft/ft_strlen.c Libft/ft_strcmp.c Libft/ft_strcat.c \
	  Libft/ft_strlcat.c Libft/ft_putstr_fd.c Libft/ft_putchar_fd.c \
	  Libft/ft_isdigit.c Libft/ft_isalpha.c Libft/ft_isalnum.c Libft/ft_atoi.c\
	  Libft/ft_strdup.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror


INC = -I./libft/includes/

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	gcc -g $(FLAG) $(INC) -o $@ -c $< 

clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
