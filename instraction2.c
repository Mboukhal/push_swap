/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:07:41 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/05 02:03:30 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_shift(looped_stack *s)
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
        if (s->top + i > s->index_last)
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
static void ft_shift_down(looped_stack *s)
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

void    ra_rb_rr(looped_stack *sa,looped_stack *sb, int status)
{
    if (status == RA)
        ft_shift(sa);
    if (status == RB)
        ft_shift(sb);
    if (status == RR)
    {
        ft_shift(sa);
        ft_shift(sb);
    }
}
    

void    rra_rrb_rrr(looped_stack *sa,looped_stack *sb, int status)
{
    if (status == RRA)
        ft_shift_down(sa);
    if (status == RRB)
        ft_shift_down(sb);
    if (status == RRR)
    {
        ft_shift_down(sa);
        ft_shift_down(sb);
    }
}
