/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:30:16 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/23 16:47:16 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_valid(char *av)
{
	if (av[0] == 'r' && av[1] == 'a' && av[2] == '\n')
		return (RA);
	else if (av[0] == 'r' && av[1] == 'b' && av[2] == '\n')
		return (RB);
	else if (av[0] == 'r' && av[1] == 'r' && av[2] == '\n')
		return (RR);
	else if (av[0] == 's' && av[1] == 'a' && av[2] == '\n')
		return (SA);
	else if (av[0] == 's' && av[1] == 'b' && av[2] == '\n')
		return (SB);
	else if (av[0] == 's' && av[1] == 's' && av[2] == '\n')
		return (SS);
	else if (av[0] == 'p' && av[1] == 'a' && av[2] == '\n')
		return (PA);
	else if (av[0] == 'p' && av[1] == 'b' && av[2] == '\n')
		return (PB);
	else if (av[0] == 'r' && av[1] == 'r' && av[2] == 'a' && av[3] == '\n')
		return (RRA);
	else if (av[0] == 'r' && av[1] == 'r' && av[2] == 'b' && av[3] == '\n')
		return (RRB);
	else if (av[0] == 'r' && av[1] == 'r' && av[2] == 'r' && av[3] == '\n')
		return (RRR);
	return (-2);
}

void	loop_back(t_stack *sa, t_stack *sb)
{
	int		i;
	int		l;
	char	*s;

	i = 0;
	l = 0;
	while (1)
	{
		s = get_next_line(STDIN_FILENO);
		if (!s)
			break ;
		i = ft_valid(s);
		free(s);
		if (i == -2)
			break ;
		exec_instration(sa, sb, i, PRINT_OFF);
		l++;
	}
	if (l == 0 || i == -2)
	{
		write(STDERR_FILENO, "Error\n", 6);
		exit (EXIT_FAILURE);
	}
	free(s);
}

void	sort_stack_checker(int *stack, int size)
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
	free(sa->data);
	free(sb->data);
	free(sa);
	free(sb);
}
