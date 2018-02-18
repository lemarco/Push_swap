#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ihoienko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/02 12:17:05 by ihoienko          #+#    #+#              #
#    Updated: 2018/02/02 12:17:06 by ihoienko         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAMECH = checker
NAMEPS = push_swap
SRCPS =  push_swap.o ft_ps_valid_and_fill.o ft_ps_is_sort.c ft_ps_ops1.o \
		ft_ps_ops2.o ft_ps_median.o ft_ps_check_and_fill.c \
		ft_ps_find_operation.o ft_ps_main_algo_1.o \
		ft_ps_main_algo_2.o ft_ps_algo_five.o
SRCCH = ft_ps_checker.o ft_ps_valid_and_fill.o ft_ps_ops1.o \
		ft_ps_ops2.o ft_ps_median.o\
		ft_ps_find_operation.o ft_ps_main_algo_1.o \
		ft_ps_main_algo_2.o ft_ps_algo_five.o
CFLAGS = -Wall -Werror -Wextra -O3
PS_OBJ = $(patsubst %.c, %.o, $(SRCPS))
CH_OBJ = $(patsubst %.c, %.o, $(SRCCH))

all: $(NAMEPS) $(NAMECH)

$(NAMEPS): $(PS_OBJ)
	make -C ./libft
	gcc $(FLAGS) -o $@ $(SRCPS) libft/libft.a

$(NAMECH): $(CH_OBJ)
	gcc $(CFLAGS) -o $@ $(SRCCH) libft/libft.a

%.o: %.c
	gcc $(CFLAGS) -I ./libft/ -o $@ -c $<

clean:
	rm -f $(PS_OBJ)
	rm -f $(CH_OBJ) $(NAMEPS)

fclean: clean
	make fclean -C ./libft
	rm -f $(PS_OBJ) $(NAMECH)
	rm -f $(CH_OBJ) $(NAMEPS)

re: fclean all

.PHONY: all clean fclean re