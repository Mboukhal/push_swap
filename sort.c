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

static t_stack  *set_stack_archi(int *stack, int size)
{
    t_stack  *data;
    data = malloc(sizeof(t_stack));
    data->top = cp_stack(stack, size);
        data->size = size;
    return (data);
}

static void    ft_bzero_int(int *s, int size)
{
    int i;
    
    i = 0;
    while (i < size)
        s[i++] = 0; 
}

void    sort_stack(int *stack, int size)
{
    t_stack    *sa;
    t_stack    *sb;
    int             zero[size];

    ft_bzero_int(zero, size);
    sa = set_stack_archi(stack, size);
    sb = set_stack_archi(zero, size);
    
    // p_stack(sa->top, sa->size);
    /*##############################################
    #               execute cmd and algo
    ################################################*/
    
    printf("----------------\n");
    p_loop(sa);
    printf("----------------\n");

    int l = ft_pop(sa);
    int r = ft_pop(sa);
    r = ft_pop(sa);
    r = ft_pop(sa);
    r = ft_pop(sa);
    r = ft_pop(sa);
    r = ft_pop(sa);
    printf("--------------dfg--\n");
    printf("|%d|\n", l);
    printf("|%d|\n", r);
    printf("-----------dfg-----\n");
    // ft_push();
    // pa_pb(sa, sb, PB);
    // pa_pb(sa, sb, PB);
    // pa_pb(sa, sb, PA);

    p_loop(sa);
    printf("----------------\n");
    // p_loop(sb);
    

    /*##############################################*/

    // free(sb->top);
    free(sb);
    // free(sa->top);
    free(sa);
}