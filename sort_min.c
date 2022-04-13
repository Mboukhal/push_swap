/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:45:31 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/13 01:21:29 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*   sorte five element or less hard coded
*/

// int get_min(t_stack *s)
// {
//     int min;
//     int i;

//     i = 1;
//     min = s->data[0];
//     while (i < s->size)
//     {
//         if (min > s->data[i])
//             min = s->data[i];
//         i++;
//     }
//     return(min);
// }

int get_next_min(t_stack *s, int min)
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

void    main_sort_min(t_stack *sa)
{
    int min;
    int next_min;

    // min = get_min(sa);
    min = get_next_min(sa, INT_MIN);
    next_min = get_next_min(sa, min);
    // printf("|%d| |%d|\n", min, next_min);
}