/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:06:16 by mboukhal          #+#    #+#             */
/*   Updated: 2022/03/23 21:12:04 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

                // alloc and set stack
void    set_stack(int count, char **numbers, int *stack)
{
    int iter;
    int index;

    iter = 0;
    index = 1;
    while (iter < count - 1)
        stack[iter++] = ft_atoi(numbers[index++]);
}