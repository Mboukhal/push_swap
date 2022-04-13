/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:14:16 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/13 22:34:10 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void algo(t_stack *sa, t_stack *sb)
{
    if (sa->size <= 5)
        main_sort_min(sa, sb);
    else
       main_sort_big(sa, sb);
}