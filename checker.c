/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:15:15 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/18 11:57:25 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    int size;
    int *stack;

    size = ac - 1;
    stack = check_av(av, size);
    sort_stack_checker(stack, size);
    free(stack);

    return (EXIT_SUCCESS);
}