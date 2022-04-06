/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   looped_list_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:51:46 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/06 00:59:40 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap(int *s)
{
    int tmp;

    tmp = s[0];
    s[0] = s[1];
    s[1] = tmp;
}

                    // if pop (-1) stack empty
int ft_pop(looped_stack *s)
{
    int poped;

    if(s->size == 0)
        return (-1);
    poped = *s->top;
    if (s->top == s->index_last)
        s->top = s->index_first;
    else
        s->top++;
    s->size--;
    return (poped);
}

void ft_push(looped_stack *s, int data)
{
    if (s->top == s->index_first)
        s->top = s->index_last;
    else
        s->top--;
    *s->top = data;
    s->size++;
}

void ft_shift(looped_stack *s)
{
    int i;
    int tmp;
    int new_i;
    int last_index;

    i = 0;
    new_i = 0;
    last_index = 0;
    tmp = s->top[0];
    while (i < s->size)
    {
        if ((s->top + i) > s->index_last)
            last_index = 1;
        if (last_index == 1)
        {
            s->index_first[new_i] = s->index_first[new_i + 1];
            new_i++;
        }
        else
            s->top[i] = s->top[i + 1];
        i++;
    }
    if (last_index == 1)
        s->index_first[new_i - 1] = tmp;
    else
        s->top[i - 1] = tmp;
}
                    // TODO: Need to be fixed
void ft_shift_down(looped_stack *s)
{
    int i;
    int tmp;
    int new_i;
    int last_index;

    i = 0;
    new_i = 0;
    last_index = 0;
    tmp = s->bottom[0];
    while (i < s->size)
    {
        if (s->top - i < s->index_last)
            last_index = 1;
        if (last_index == 1)
        {
            s->index_first[new_i] = s->index_first[new_i - 1];
            new_i--;
        }
        else
            s->top[i] = s->top[i - 1];
        i--;
    }
    if (last_index == 1)
        s->index_first[new_i + 1] = tmp;
    else
        s->top[i + 1] = tmp;
}