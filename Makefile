# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amerrouc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 16:50:34 by amerrouc          #+#    #+#              #
#    Updated: 2019/01/02 15:35:30 by amerrouc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = chs_type.c convert.c disp.c flags.c ft_printf.c functions.c nbr_base.c \
	  padding.c pre.c print_int.c print_txt.c print_uint.c util.c \
	  Libft/ft_strnew.c Libft/ft_strlen.c Libft/ft_strcmp.c Libft/ft_strcat.c \
	  Libft/ft_strlcat.c Libft/ft_putstr.c Libft/ft_putchar.c \
	  Libft/ft_isdigit.c Libft/ft_isalpha.c Libft/ft_atoi.c

OBJ = $(SRC:.c=.o)

#FLAG = -Wall -Wextra -Werror

LIB = libft/libft.a

INC = -I./libft/includes/

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

$(LIB):
	make -C libft/ fclean
	make -C ./libft/

%.o: %.c
	gcc -g $(FLAG) $(INC) -o $@ -c $< 

clean:
	#make -C libft/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
