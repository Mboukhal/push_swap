/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:30:16 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/18 14:47:18 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_valid(char *av)
{
    if (av[0] == 'r' && av[1] == 'a' && av[2] == '\n')
        return(RA);
    else if (av[0] == 'r' && av[1] == 'b' && av[2] == '\n')
        return(RB);
    else if (av[0] == 'r' && av[1] == 'r' && av[2] == 'a' && av[3] == '\n')
        return(RRA);
    else if (av[0] == 'r' && av[1] == 'r' && av[2] == 'b' && av[3] == '\n')
        return(RRB);
    else if (av[0] == 'r' && av[1] == 'r' && av[2] == 'r' && av[3] == '\n')
        return(RRR);
    else if (av[0] == 'r' && av[1] == 'r' && av[2] == '\n')
        return(RR);
    else if (av[0] == 's' && av[1] == 'a' && av[2] == '\n')
        return(SA);
    else if (av[0] == 's' && av[1] == 'b' && av[2] == '\n')
        return(SB);
    else if (av[0] == 's' && av[1] == 's' && av[2] == '\n')
        return(SS);
    else if (av[0] == 'p' && av[1] == 'a' && av[2] == '\n')
        return(PA);
    else if (av[0] == 'p' && av[1] == 'b' && av[2] == '\n')
        return(PB);
    write(STDERR_FILENO, "Error\n", 6);
    write(STDERR_FILENO, "\tNon valide instraction !\n", 27);
    exit (EXIT_FAILURE);
}

int read_instraction(void)
{
    char s[4];
    int status;

    status = read(STDIN_FILENO, s, 4);
    if (s[0] == '\n')
        return (EOF);
    return (ft_valid(s));
}

void    loop_back(void)
{
    int     i;

    i = 0;
    while(i != EOF)
        i = read_instraction();
}

void    sort_stack_checker(int *stack, int size)
{
    
    
    // loop_back();
}