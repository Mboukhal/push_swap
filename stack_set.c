/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 16:06:16 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/02 15:57:07 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

                // alloc and set stack
int    *set_stack(char **numbers, int size)
{
    int index;
    int *stack;

    index = 0;
    stack = malloc(sizeof(int) * size + 1);
    while (numbers[index++])
        stack[index - 1] = ft_atoi(numbers[index - 1]);
    return (stack);
}