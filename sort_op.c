/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:39:45 by mboukhal          #+#    #+#             */
/*   Updated: 2022/03/15 15:39:45 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_sorted(t_stack *s)
{
    int i;

    i = 0;
    while (i++ <= s->size)
        if (s->data[i - 1] > s->data[i])
            return(0);
    return(1);
}

t_stack *init_stack(int *stack, int size, int status)
{
    t_stack *set;
    int     i;

    set = malloc(sizeof(t_stack));
    if (!set)
        return (NULL);
    i = -1;
    set->data = malloc(sizeof(int) * size);
    if (!set->data)
        return (NULL);
    if (status == 1)
    {
        set->size = size;
    }
    else
        set->size = 0;
    while (i++ < size)
        if (set->size == 0)
            set->data[i] = stack[i];
        else
            set->data[i] = stack[i];
    return (set);
}

void    sort_stack(int *stack, int size)
{
    t_stack    *sa;
    t_stack    *sb;

    sa = init_stack(stack, size, 1);
    sb = init_stack(stack, size, 0);
    if (sa->size <= 5)
        main_sort_min(sa, sb);
    else
       main_sort_big(sa, sb);
    if (sa->size > 0)
        free(sa->data);
    if (!sa)
        free(sa);
    if (sb->size > 0)
        free(sb->data);
    if (!sb)
        free(sb);
}

                // alloc and set stack
int    *set_stack(char **numbers, int size)
{
    int index;
    int *stack;

    index = 0;
    stack = malloc(sizeof(int) * (size));
    if (!stack)
        return (NULL);
    while (index < size)
    {
        stack[index] = ft_atoi(numbers[index]);
        index++;
    }
    return (stack);
}