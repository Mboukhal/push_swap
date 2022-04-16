# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/14 12:49:36 by mboukhal          #+#    #+#              #
#    Updated: 2022/04/16 23:45:00 by mboukhal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.DEFAULT_GOAL		= all
NAME				= push_swap
CFILES				= push_swap.c error_ps.c sort_op.c					\
					 cote_ps.c sort_max.c list_func.c instraction.c 	\
					 sort_min.c ft_atoi.c ft_itoa.c ft_put.c ft_split.c 
CFLAGS				= -Wall -Wextra -Werror

OBJS			= $(CFILES:.c=.o)

clean:
	$(RM) -rf $(OBJS)

fclean: clean
	$(RM) -rf $(NAME)

re: fclean all

.c.o:
	$(CC) $(CFLAGS) -c $< 

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	
all: $(NAME)

.PHONY: re fclean all clean
