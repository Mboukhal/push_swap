/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:45:31 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/13 22:30:14 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*   sorte five element or less hard coded
*/

static int get_next_min(t_stack *s, int min)
{
    int i;
    int m;

    i = 1;
    m = s->data[0];
    while (i < s->size)
    {
        if (m == INT_MIN)
            return (m);
        if (m > s->data[i] && s->data[i] > min)
            m = s->data[i];
        i++;
    }
    return (m);
}

static void    sort_3(int *min, t_stack *s)
{
    if (s->data[0] == min[0] && s->data[1] != min[1])
    {
        rra_rrb_rrr(s, NULL, RRA);
        sa_sb_ss(s, NULL, SA);
    }
    else if (s->data[0] == min[1])
    {
        if (s->data[1] == min[0])
			sa_sb_ss(s, NULL, SA);
		else
			rra_rrb_rrr(s, NULL, RRA);
    }
    else
    {
        if (s->data[1] == min[0])
			ra_rb_rr(s, NULL, RA);
		else if (s->data[1] == min[1])
		{
            sa_sb_ss(s, NULL, SA);
            rra_rrb_rrr(s, NULL, RRA);
        }
    }
}

static void    sort_4(int *min, t_stack *sa, t_stack *sb)
{
	while (sa->size == 4)
		if (sa->data[0] == min[0])
            pa_pb(sa, sb, PB);
		else
            ra_rb_rr(sa, sb, RA);
    min[0] = get_next_min(sa, INT_MIN);
    min[1] = get_next_min(sa, min[0]);
    sort_3(min, sa);
	while (sb->size)
        pa_pb(sa, sb, PA);
    
}

static void    sort_5(int *min, t_stack *sa, t_stack *sb)
{

    while (sa->size == 5)
		if (sa->data[0] == min[0])
            pa_pb(sa, sb, PB);
		else
            ra_rb_rr(sa, sb, RA);
    min[0] = get_next_min(sa, INT_MIN);
    min[1] = get_next_min(sa, min[0]);
    sort_4(min, sa, sb);
	while (sb->size)
        pa_pb(sa, sb, PA);
}

void    main_sort_min(t_stack *sa, t_stack *sb)
{
    int min[2];

    min[0] = get_next_min(sa, INT_MIN);
    min[1] = get_next_min(sa, min[0]);
    if (sa->size == 2)
        sa_sb_ss(sa, NULL, SA);
    else if (sa->size == 3)
        sort_3(min, sa);
    else if (sa->size == 4)
        sort_4(min, sa, sb);
    else if (sa->size == 5)
        sort_5(min, sa, sb);
}