/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:50:59 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/02 15:56:15 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void p_stack(int *stack, int count)
{
    int i = 0;
    while (i < count)
    {
        printf("|%d|\n", stack[i]);
        i++;
    }
    printf("--------------------\n");
    
}

                /*
                    main {push_swap}
                        - cheak for integer value and limit
                        - set satck_a as integer list 
                        - cheak for duplicate value
                        - __sort_values__ 
                */
int main(int ac, char **av)
{
    // int     stack_in;
    char    **str;
    int     size;
    int     i;
    int     *stack_in;

    size = ac - 1;
    if (ac < 2)
        return (EXIT_FAILURE);
    else if (ac == 2)
    {
        str = ft_split(av[1], ' ');
        size = 0;
        while (str[size++]);
        size--;
        stack_in = set_stack(str, size);
        check_all(str, stack_in, size);
        i = 0;
        while (str[i])
            free(str[i++]);
        free(str);
    }
    else
    {
        stack_in = set_stack(&av[1], size);
        check_all(av, stack_in, size);
    }
    p_stack(stack_in, size);
    // sort_stack(stack_a, stack_b);
    free(stack_in);
    return (EXIT_SUCCESS); 
}