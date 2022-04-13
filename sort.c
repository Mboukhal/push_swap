/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:20:11 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/13 22:46:52 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	int	i;
	int	num;
	int	size;

	i = 0;
	while (!is_sorted(*a))
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
	*/

void    main_sort_big(t_stack *sa, t_stack *sb)
{
	int	i;
	int	size;

	i = 0;
	while (!is_sorted(sa))
	{
		size = sa->size;
		printf("\t\t%d\n", size);
		while (size--)
		{
			if ((*(sa->data) >> i & 1) == 1)
				ra_rb_rr(sa, NULL, RA);
				// r(a, "ra");
			else
				pa_pb(sa, sb, PB);
				// p(a, b, "pb");
			if (is_sorted(sa))
				break ;
		}
		while (sb->size)
			pa_pb(sa, sb, PA);
			// p(a, b, "pa");
		i++;
	}
}
