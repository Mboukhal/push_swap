# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 12:49:36 by mboukhal          #+#    #+#              #
#    Updated: 2022/04/13 21:58:57 by mboukhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.DEFAULT_GOAL		= all
NAME				= push_swap
CFILES				= torm.c push_swap.c error_ps.c sort_op.c		\
					 cote_ps.c sort.c list_func.c instraction.c 	\
					 algo.c sort_min.c ft_atoi.c ft_itoa.c ft_put.c \
					 ft_split.c 
CFLAGS				= -Wall -Wextra -Werror 

OBJS			= $(CFILES:.c=.o)

clean:
	@$(RM) -rf $(OBJS)

fclean: clean
	@$(RM) -rf $(NAME)

re: fclean all

.c.o:
	@$(CC) $(CFLAGS) -c $< 

$(NAME):$(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -g -fsanitize=address


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
