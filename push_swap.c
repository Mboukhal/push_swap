/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:50:59 by mboukhal          #+#    #+#             */
/*   Updated: 2022/03/23 21:15:58 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

                /*
                    main {push_swap}
                        - cheak for integer value and limit
                        - set satck_a as integer list 
                        - cheak for duplicate value
                        - __sort_values__ 
                */
int main(int ac, char **av)
{
    int stack_a[ac + 1];

    if (ac < 2)
        exit(EXIT_FAILURE);
    cheak_isint(av);
    cheak_limit(av);
    set_stack(ac, av, stack_a); 
    cheak_isdup(stack_a, ac);
    
    return (EXIT_SUCCESS); 
}