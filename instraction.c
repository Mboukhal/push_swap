/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:07:41 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/13 23:02:33 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void    ra_rb_rr(t_stack *sa,t_stack *sb, int status)
{
    if (status == RA)
    {
        ft_shift_up(sa);
        write(1, "ra\n", 3);
    }
    if (status == RB)
    {
        ft_shift_up(sb);
        write(1, "rb\n", 3);
    }
    if (status == RR)
    {
        ft_shift_up(sa);
        ft_shift_up(sb);
        write(1, "rr\n", 3);
    }
}   

void    rra_rrb_rrr(t_stack *sa,t_stack *sb, int status)
{
    if (status == RRA)
    {
        ft_shift_down(sa);
        write(1, "rra\n", 4);
    }
    if (status == RRB)
    {
        ft_shift_down(sb);
        write(1, "rrb\n", 4);
    }
    if (status == RRR)
    {
        ft_shift_down(sa);
        ft_shift_down(sb);
        write(1, "rrr\n", 4);
    }
}

void    sa_sb_ss(t_stack *sa, t_stack *sb, int status)
{
    if (status == SA && sa->size > 1)
    {
        ft_swap_head_stack(sa);
        write(1, "sa\n", 3);
    }
    if (status == SB && sb->size > 1)
    {
        ft_swap_head_stack(sb);
        write(1, "sb\n", 3);
    }
    if (status == SS)
    {
        if (sa->size > 1)
            ft_swap_head_stack(sa);
        if (sb->size > 1)
            ft_swap_head_stack(sb);
        write(1, "ss\n", 3);
    }
}

void    pa_pb(t_stack *sa,t_stack *sb, int status)
{
    int tmp;

    if (status == PA)
    {
        ft_pop(sb, &tmp);
        ft_push(sa, tmp);
        write(1, "pa\n", 3);
    }
    if (status == PB)
    {
        ft_pop(sa, &tmp);
        ft_push(sb, tmp);
        write(1, "pb\n", 3);
    }
}
