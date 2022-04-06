/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:07:41 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/06 00:52:42 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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

void    sa_sb_ss(looped_stack *sa, looped_stack *sb, int status)
{
    if (status == SA && sa->size > 1)
        ft_swap(sa->top);
    if (status == SB && sb->size > 1)
        ft_swap(sb->top);
    if (status == SS)
    {
        if (sa->size > 1)
            ft_swap(sa->top);
        if (sb->size > 1)
            ft_swap(sb->top);
    }
}

void    pa_pb(looped_stack *sa,looped_stack *sb, int status)
{
    int tmp;

    if (status == PA)
    {
        tmp = ft_pop(sb);
        ft_push(sa, tmp);
    }
    if (status == PB)
    {
        tmp = ft_pop(sa);
        ft_push(sb, tmp);
    }
}
