/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:30:16 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/18 12:05:06 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    loop_back(void)
{
    char **av;
    int     i;

    i = 0;
    av = malloc(sizeof(char));
    if (!av)
        return ;
    while(1)
    {
        av[i] = get_next_line(STDIN_FILENO);
        if (av[i][0] == '\n')
            break;
        i++;
    }
    av[i] = NULL;
    i = 0;
    while(av[i])
        printf("==> %s\n",av[i++]);
}

void    sort_stack_checker(int *stack, int size)
{
    (void)stack;
    (void)size;
    loop_back();
}