# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 12:49:36 by mboukhal          #+#    #+#              #
#    Updated: 2022/04/18 15:09:58 by mboukhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.DEFAULT_GOAL		= test
NAME				= push_swap
BONUS				= checker
CFILES				= push_swap.c error_ps.c sort_op.c ft_split.c		\
					 cote_ps.c sort_max.c list_func.c instraction.c 	\
					 sort_min.c ft_atoi.c ft_itoa.c ft_put.c 			
					 
CFBONUS				= checker.c checker_op.c error_ps.c sort_op.c 		\
					 cote_ps.c sort_max.c list_func.c instraction.c 	\
					 sort_min.c ft_atoi.c ft_itoa.c ft_put.c ft_split.c 	
CFLAGS				= -Wall -Wextra -Werror

OBJS			= $(CFILES:.c=.o)
BOBJS			= $(CFBONUS:.c=.o)

clean:
	@$(RM) -rf $(OBJS) $(BOBJS)

fclean: clean
	@$(RM) -rf $(NAME) $(BONUS)

re: fclean all

.c.o:
	@$(CC) $(CFLAGS) -c $< 

$(NAME):$(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -g -fsanitize=address

$(BONUS):$(BOBJS)
	@$(CC) $(CFLAGS) -o $(BONUS) $(BOBJS) -g -fsanitize=address
	
all: $(NAME)

bonus: $(BONUS)

test: all bonus clean

.PHONY: re fclean all clean bonus
