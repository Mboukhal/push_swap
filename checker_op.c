/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:30:16 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/18 16:06:11 by mboukhal         ###   ########.fr       */
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
    char s[5];
    int i;

    i = 0;
    if (read(STDIN_FILENO, &s[0], 1) == 0)
        return (EOF);
    if (s[0] == 'r' || s[0] == 's' || s[0] == 'p')
    {
        i++;
        read(STDIN_FILENO, &s[1], 1);
        if (s[1] == 'r' || s[1] == 'a' || s[1] == 'b')
        {
            i++;
            read(STDIN_FILENO, &s[2], 1);
            if (s[2] == 'r' || s[2] == 'a' || s[2] == 'b')
            {
                i++;
                read(STDIN_FILENO, &s[3], 1);
            }
        }
    }
    s[i + 1] = '\0';
    return (ft_valid(s));
}

void    loop_back(t_stack *sa, t_stack *sb)
{
    int     i;

    i = 0;
    while(i != EOF)
    {
        i = read_instraction();
        exec_instration(sa, sb, i, PRINT_OFF);
    }
}

void    sort_stack_checker(int *stack, int size)
{
    t_stack		*sa;
	t_stack		*sb;

	sa = init_stack(stack, size, 1);
	sb = init_stack(stack, size, 0);
    free(stack);
	sb->size_max = sa->size;
	sa->size_max = sa->size;
    loop_back(sa, sb);
    if (is_sorted(sa) && sb->size == 0)
        write(STDOUT_FILENO, "OK\n", 3);
    else
        write(STDOUT_FILENO, "KO\n", 3);
    if (sb->size > 0)
		free(sa->data);
	if (sb->size > 0)
		free(sb->data);
	free(sa);
	free(sb);
}