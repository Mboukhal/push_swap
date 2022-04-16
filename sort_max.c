/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:20:11 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/16 17:41:07 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*tmp_func(t_stack *s)
{
	int	*tmp;
	int	ss;
	int	i;

	tmp = malloc(sizeof(int) * s->size);
	ss = s->size;
	i = -1;
	while (i++ < ss - 1)
		tmp [i] = s->data[i];
	while (ss)
	{
		i = -1;
		while (i++ < s->size - 2)
			if (tmp[i] > tmp[i + 1])
				ft_swap_int(&tmp[i], &tmp[i + 1]);
		ss--;
	}
	return (tmp);
}

void	stack_to_index(t_stack *s)
{
	int	i;
	int	*tmp;
	int	ss;

	tmp = tmp_func(s);
	ss = 0;
	while (ss < s->size)
	{
		i = 0;
		while (i < s->size)
		{
			if (tmp[i++] == s->data[ss])
			{
				s->data[ss] = i - 1;
				break ;
			}
		}
		ss++;
	}
	free(tmp);
}

void	main_sort_big(t_stack *sa, t_stack *sb)
{
	int	i;
	int	num;
	int	size;

	stack_to_index(sa);
	i = 0;
	while (!is_sorted(sa))
	{
		size = sa->size;
		while (size--)
		{
			num = *(sa->data);
			if ((num >> i & 1) == 1)
				ra_rb_rr(sa, sb, RA);
			else
				pa_pb(sa, sb, PB);
			if (is_sorted(sa))
				break ;
		}
		while (sb->size)
			pa_pb(sa, sb, PA);
		i++;
	}
}
