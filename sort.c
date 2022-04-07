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

looped_stack  *set_stack_archi(int *stack, int size, int status)
{
    looped_stack  *data;
    data = malloc(sizeof(looped_stack));
    data->index_first = cp_stack(stack, size, status);
    if (status == 0)
    {
        data->top = data->index_first;
        data->size = size;
        data->index_last = data->index_first + size;
        data->bottom = data->index_first + (size - 1);
    }
    else
    {
        data->top = data->index_last;
        data->size = 0;
        data->index_last = data->index_first;
        data->bottom = data->index_first;
    }
    
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
    sa = set_stack_archi(stack, size, 0);
    sb = set_stack_archi(zero, size, 1);
    
    // p_stack(sa->top, sa->size);
    /*##############################################
    #               execute cmd and algo
    ################################################*/
    
    printf("----------------\n");
    p_loop(sa);
    printf("----------------\n");

    pa_pb(sa, sb, PB);
    pa_pb(sa, sb, PB);
    // pa_pb(sa, sb, PA);

    p_loop(sa);
    printf("----------------\n");
    p_loop(sb);
    

    /*##############################################*/

    free(sb->index_first);
    free(sb);
    free(sa->index_first);
    free(sa);
}