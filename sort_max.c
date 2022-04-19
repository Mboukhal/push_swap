/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:20:11 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/19 01:26:03 by mboukhal         ###   ########.fr       */
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
	int	size;

	stack_to_index(sa);
	i = 0;
	while (!is_sorted(sa))
	{
		size = sa->size;
		while (size--)
		{
			if (*(sa->data) >> i & 1)
				exec_instration(sa, sb, RA, PRINT_ON);
			else
				exec_instration(sa, sb, PB, PRINT_ON);
			if (is_sorted(sa))
				break ;
		}
		while (sb->size)
			exec_instration(sa, sb, PA, PRINT_ON);
		i++;
	}
}
