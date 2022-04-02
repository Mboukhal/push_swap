/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cote_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 22:02:59 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/02 15:49:21 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    valid_cote(char *str)
{
    int iter;

    iter = 0;
    while (str[iter])
    {
        if (!(str[iter] == ' ' || str[iter] == '-' ||
            (str[iter] <= '9' && str[iter] >= '0')) )
            cheak_isint(&str);
        iter++;
    }
    return (0);
}

void    check_all(char **str, int *stack_in, int size)
{
    cheak_isint(str);
    cheak_limit(str);
    cheak_isdup(stack_in, size);
}