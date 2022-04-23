/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:07:41 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/23 15:24:56 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_instration(t_stack *sa, t_stack *sb, int ins, int print)
{
	if (print == 1)
		print_ins(ins);
	if (ins >= RA && ins <= RR)
		ra_rb_rr(sa, sb, ins);
	else if (ins >= RRA && ins <= RRR)
		rra_rrb_rrr(sa, sb, ins);
	else if (ins >= SA && ins <= SS)
		sa_sb_ss(sa, sb, ins);
	else if (ins == PA || ins == PB)
		pa_pb(sa, sb, ins);
}

void	ra_rb_rr(t_stack *sa, t_stack *sb, int status)
{
	if (status == RA)
		ft_shift_up(sa);
	if (status == RB)
		ft_shift_up(sb);
	if (status == RR)
	{
		ft_shift_up(sa);
		ft_shift_up(sb);
	}
}

void	rra_rrb_rrr(t_stack *sa, t_stack *sb, int status)
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

void	sa_sb_ss(t_stack *sa, t_stack *sb, int status)
{
	if (status == SA && sa->size > 1)
		ft_swap_int(&sa->data[0], &sa->data[1]);
	if (status == SB && sb->size > 1)
		ft_swap_int(&sb->data[0], &sb->data[1]);
	if (status == SS)
	{
		if (sa->size > 1)
			ft_swap_int(&sa->data[0], &sa->data[1]);
		if (sb->size > 1)
			ft_swap_int(&sb->data[0], &sb->data[1]);
	}
}

void	pa_pb(t_stack *sa, t_stack *sb, int status)
{
	int	tmp[1];

	if (status == PA)
	{
		ft_pop(sb, tmp);
		ft_push(sa, tmp);
	}
	if (status == PB)
	{
		ft_pop(sa, tmp);
		ft_push(sb, tmp);
	}
}
