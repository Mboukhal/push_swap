/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:06:16 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/03 17:42:44 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

                // alloc and set stack
int    *set_stack(char **numbers, int size)
{
    int index;
    int *stack;

    index = 0;
    stack = malloc(sizeof(int) * (size));
    while (index < size)
    {
        stack[index] = ft_atoi(numbers[index]);
        index++;
    }
    return (stack);
}