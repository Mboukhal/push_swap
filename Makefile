# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 12:49:36 by mboukhal          #+#    #+#              #
#    Updated: 2022/04/13 00:54:11 by mboukhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.DEFAULT_GOAL		= all
NAME				= push_swap
LIBFT_PHAT			= libft/
CFILES				= torm.c push_swap.c error_ps.c stack_set.c \
					 cote_ps.c sort.c list_func.c instraction.c \
					 algo.c sort_min.c
CFLAGS				= -Wall -Wextra -Werror 
LIBFT_MAKE 			= make $@ -C $(LIBFT_PHAT)

OBJS			= $(CFILES:.c=.o)

clean:
	@$(RM) -rf $(OBJS)
	@# $(LIBFT_MAKE)

fclean: clean
	@$(RM) -rf $(NAME)
	@# $(LIBFT_MAKE)

re: fclean all

.c.o:
	@$(CC) $(CFLAGS) -c $< 

$(NAME):$(OBJS)
	@# make -C $(LIBFT_PHAT)
	@$(CC) -o $(NAME) $(OBJS) $(LIBFT_PHAT)ft_*.o -g -fsanitize=address


test: re clean 
	@./push_swap 54 -456 0 89 546 64 684 2147483647 65 -2147483648
	@echo "ok" 

test_limit: re clean 
	@./push_swap -2147483648 -2147483649 ; ./push_swap 2147483647 2147483648 

test_dup: re clean 
	@./push_swap 54 89  546 684 2147483647 64 65 6457 -2147483648 
	@./push_swap 54 89  546 684 2147483647 64 65 64 -2147483648 
	
all: $(NAME) clean

.PHONY: re fclean all clean
