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

// static void    ft_bzero_int(int *s, int size)
// {
//     int i;
    
//     i = 0;
//     while (i < size)
//         s[i++] = 0; 
// }

t_stack *init_stack(int *stack, int size, int status)
{
    t_stack *set;
    int     i;

    set = malloc(sizeof(t_stack));
    set->data = malloc(sizeof(int) * size);
    i = -1;
    set->size = size;
    if (status == 1)
        while (i++ < size)
            set->data[i] = stack[i];
    else
        while (i++ < size)
            set->data[i] = 0;
    return (set);
}

void    sort_stack(int *stack, int size)
{
    t_stack    *sa;
    t_stack    *sb;

    sa = init_stack(stack, size, 1);
    sb = init_stack(stack, size, 0);
    p_loop(sa);
    /*##############################################
    #               execute cmd and algo
    ################################################*/
    

    

    /*##############################################*/
    free(sa->data);
    free(sa);
    free(sb->data);
    free(sb);
}