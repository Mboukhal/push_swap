/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:07:41 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/07 01:35:11 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void    ra_rb_rr(t_stack *sa,t_stack *sb, int status)
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
    

void    rra_rrb_rrr(t_stack *sa,t_stack *sb, int status)
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

void    sa_sb_ss(t_stack *sa, t_stack *sb, int size, int status)
{
    if (status == SA && size > 1)
        ft_swap_head_stack(sa);
    if (status == SB && size > 1)
        ft_swap_head_stack(sb);
    if (status == SS)
    {
        if (size > 1)
            ft_swap_head_stack(sa);
        if (size > 1)
            ft_swap_head_stack(sb);
    }
}

void    pa_pb(t_stack *sa,t_stack *sb, int status)
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
