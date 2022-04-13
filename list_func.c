/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:51:46 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/13 23:18:52 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap_head_stack(t_stack *s)
{
    int tmp;

    tmp = s->data[0];
    s->data[0] = s->data[1];
    s->data[1] = tmp;
}

                    // if pop (-1) stack empty
void ft_pop(t_stack *s, int *poped)
{
    int *tmp;
    int i;

    if (s->size == 0)
        return ;
    *poped = s->data[0];
    s->size--;
    tmp = malloc(sizeof(int) * s->size);
    if (!tmp)
        return ;
    i = 0;
    while (i < s->size)
    {
        tmp[i] = s->data[i + 1];
        i++;
    }
    free(s->data);
    s->data = tmp;
}

void ft_push(t_stack *s, int push)
{
    int *tmp;
    int i;

    s->size++;
    tmp = malloc(sizeof(int) * s->size);
    if (!tmp)
            return ;
    tmp[0] = push; 
    if (s->size > 1)
    {
        i = 0;
        while (i < s->size)
        {
            tmp[i + 1] = s->data[i];
            i++;
        }
        // free(s->data);
    }
    s->data = tmp;
}

void ft_shift_up(t_stack *s)
{
    int i;
    int tmp;

    if (s->size <= 1)
        return ;
    tmp = s->data[0];
    i = -1;
    while (i++ < s->size)
        s->data[i] = s->data[i + 1];
    s->data[i - 2] = tmp;
}

void ft_shift_down(t_stack *s)
{
    int i;
    int tmp;

    if (s->size <= 1)
        return ;
    tmp = s->data[s->size - 1];
    i = s->size;
    while (i > 0)
    {
        s->data[i] = s->data[i - 1];
        i--;
    }
    s->data[0] = tmp;
}