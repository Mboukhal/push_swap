/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:39:45 by mboukhal          #+#    #+#             */
/*   Updated: 2022/03/15 15:39:45 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

looped_stack  *set_stack_archi(int *stack, int size)
{
    looped_stack  *data;

    data = malloc(sizeof(looped_stack));
    data->top = cp_stack(stack, size);
    data->index_first = data->top;
    data->size = size;
    data->index_last = data->index_first + size;
    data->bottom = data->index_first + (size - 1);
    return (data);
}
void    ft_bzero_int(int *s, int size)
{
    int i;
    
    i = 0;
    while (i < size)
        s[i++] = 0; 
}
void    sort_stack(int *stack, int size)
{
    looped_stack    *sa;
    looped_stack    *sb;
    int             zero[size];

    ft_bzero_int(zero, size);
    printf("%d\n", zero[1]);
    sa = set_stack_archi(stack, size);
    sb = set_stack_archi(zero, size);
    // p_stack(sa->top, sa->size);
    /*##############################################
    #               execute cmd and algo
    ################################################*/
    // p_stack(sb->top, sb->size);
    // printf("&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
    p_loop(sa);
    printf("----------------------\n");
    
    // pa_pb(sa, sb, PB);
    // ra_rb_rr(sa, sb, RA);
    rra_rrb_rrr(sa, sb, RRA);
    p_loop(sa);
    printf("----------------------\n");
    p_loop(sb);
    printf("0000000000000000\n");
    p_stack(sa->index_first, sa->size + 3);
    /*##############################################*/

    free(sb->index_first);
    free(sb);
    free(sa->index_first);
    free(sa);
}