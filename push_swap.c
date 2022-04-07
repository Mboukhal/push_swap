/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:50:59 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/06 03:32:13 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    *cp_stack(int *st, int size, int status)
{
    int *stack;
    int index;

    index = 0;
    stack = malloc(sizeof(int) * size);
    if (!stack)
        return (NULL);
    if (status == 0)
        while (index++ < size)
            stack[index - 1] = st[index - 1];
    return (stack);
}

                /*
                    main {push_swap}
                        - cheak for integer value and limit
                        - set satck_a as integer list 
                        - cheak for duplicate value
                        - __sort_values__ 
                */

int    *cheak_set_cotes(int size, char *cote)
{
    char    **str;
    int     i;
    int     *stack;


    str = ft_split(cote, ' ');
    size = 0;
    while (str[size++]);
    size--;
    stack = set_stack(str, size);
    check_all(str, stack, size, 1);
    i = 0;
    while (str[i])
        free(str[i++]);
    free(str);
    return (stack);
}
int main(int ac, char **av)
{
    int     size;
    int     *stack_in;

    size = ac - 1;
    if (ac < 2)
        return (EXIT_FAILURE);
    else if (ac == 2)
        stack_in = cheak_set_cotes(size, av[1]);
    else
    {
        stack_in = set_stack(&av[1], size);
        check_all(&av[1], stack_in, size, 0);
    }
    // p_stack(stack_in, size);
    sort_stack(stack_in, size);
    free(stack_in);
    return (EXIT_SUCCESS); 
}