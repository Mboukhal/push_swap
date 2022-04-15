/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 10:55:28 by adouib            #+#    #+#             */
/*   Updated: 2022/04/15 16:00:36 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_stack **a, t_stack **b, int ac)
{
	if (ac <= 3)
		sort_three_numbers(a);
	else if (ac <= 4)
		sort_four_numbers(a, b);
	else
		sort_five_numbers(a, b);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	num;
	int	size;

	i = 0;
	while (!is_sorted(*a) && i != 1)
	{
		size = stack_size(*a);
		while (size--)
		{
			num = (*a)->number;
			if ((num >> i & 1) == 1)
				r(a, "ra");
			else
				p(a, b, "pb");
			if (is_sorted(*a))
				break ;
		}
		while (stack_size(*b))
			p(a, b, "pa");
		i++;
	}
}
