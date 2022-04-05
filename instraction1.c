/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instraction1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:05:35 by mboukhal          #+#    #+#             */
/*   Updated: 2022/03/15 22:06:01 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_swap(int *s)
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
