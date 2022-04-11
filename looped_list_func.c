/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   looped_list_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:51:46 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/07 02:15:25 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap_head_stack(t_stack *s)
{
    int tmp;

    tmp = s->stack;
    s->stack = s->next->stack;
    s->next->stack = tmp;
}

                    // if pop (-1) stack empty
int ft_pop(t_stack *s, int size)
{
    int poped;

    if (size == 0)
        return (0);
    poped = s->stack;
    s = s->next;
    size--;
    return (poped);
}

void ft_push(t_stack *s, int data, int size)
{
    t_stack     *add;
    int         tmp;

    add = malloc(sizeof(t_stack));
    if (!add)
        return ;
    tmp = s->stack;
    s->stack = data;
    add->stack = tmp;
    add->next = s;
    s = add;
    size++;
}

void ft_shift_up(t_stack *s, int size)
{
    int i;
    t_stack *h;
    int tmp;

    tmp = s->stack;
    h = s;
    while (h->next)
    {
        h->stack = h->next->stack;
        h = h->next;
    }
    h->stack = tmp;
}
                    // TODO: Need to be fixed
void ft_shift_down(t_stack *s)
{
    int i;
    int tmp;
    // int new_i;
    // int last_index;

    i = s->size;
    // new_i = 0;
    // last_index = 0;
    tmp = s->top[0];
    while (i > 0)
    {
        // if ((s->bottom - i) == s->index_first)
        // {
        //     new_i = s->size - i;
        //     last_index = 1;
        // }
        // if (last_index == 1)
        // {
        //     if ((s->bottom - i) == s->index_first)
        //         s->index_first[0] = s->bottom[new_i - 1];
        //     else
        //         s->bottom[new_i] = s->bottom[new_i - 1];
        //     new_i--;
        // }
        // else
        //     s->bottom[i] = s->bottom[i - 1];
        i--;
    }
    (s->top + 1)[0] = tmp;
}