/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:39:45 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/19 00:24:34 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_ins(int ins)
{
	if (ins == RA)
		write(1, "ra\n", 3);
	if (ins == RB)
		write(1, "rb\n", 3);
	if (ins == RR)
		write(1, "rr\n", 3);
	if (ins == RRA)
		write(1, "rra\n", 4);
	if (ins == RRB)
		write(1, "rrb\n", 4);
	if (ins == RRR)
		write(1, "rrr\n", 4);
	if (ins == SA)
		write(1, "sa\n", 3);
	if (ins == SB)
		write(1, "sb\n", 3);
	if (ins == SS)
		write(1, "ss\n", 3);
	if (ins == PA)
		write(1, "pa\n", 3);
	if (ins == PB)
		write(1, "pb\n", 3);
}

int	is_sorted(t_stack *s)
{
	int	i;

	i = 1;
	while (i < s->size)
	{
		if (s->data[i - 1] > s->data[i])
			return (0);
		i++;
	}
	return (1);
}

t_stack	*init_stack(int *stack, int size, int status)
{
	t_stack	*set;
	int		i;

	set = malloc(sizeof(t_stack));
	if (!set)
		return (NULL);
	set->data = malloc(sizeof(int) * (size + 1));
	if (!set->data)
		return (NULL);
	if (status == 1)
		set->size = size;
	else
		set->size = 0;
	i = 0;
	while (i < size)
	{
		if (set->size == 0)
			set->data[i] = stack[i];
		else
			set->data[i] = stack[i];
		i++;
	}
	return (set);
}

void	sort_stack(int *stack, int size)
{
	t_stack		*sa;
	t_stack		*sb;

	sa = init_stack(stack, size, 1);
	sb = init_stack(stack, size, 0);
	free(stack);
	sb->size_max = sa->size;
	sa->size_max = sa->size;
	if (sa->size < 6)
		main_sort_min(sa, sb);
	else
		main_sort_big(sa, sb);
	free(sa->data);
	free(sa);
	free(sb->data);
	free(sb);
}

int	*set_stack(char **numbers, int size)
{
	int	index;
	int	*stack;

	index = 0;
	stack = malloc(sizeof(int) * (size));
	if (!stack)
		return (NULL);
	while (index < size)
	{
		stack[index] = ft_atoi(numbers[index]);
		index++;
	}
	return (stack);
}
