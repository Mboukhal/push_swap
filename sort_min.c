/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 00:45:31 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/20 15:56:55 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
*   sorte five element or less hard coded
*/

static int	get_next_min(t_stack *s, int min)
{
	int	i;
	int	m;

	i = 1;
	if (s->data[0] != min)
		m = s->data[0];
	else
		m = s->data[0] + 1;
	while (i < s->size)
	{
		if (m == INT_MIN && min == INT_MIN)
			return (m);
		if (m > s->data[i] && s->data[i] > min)
				m = s->data[i];
		i++;
	}
	return (m);
}

static void	sort_3(int *min, t_stack *s)
{
	if (s->data[0] == min[0] && s->data[1] != min[1])
	{
		exec_instration(s, NULL, RRA, PRINT_ON);
		exec_instration(s, NULL, SA, PRINT_ON);
	}
	else if (s->data[0] == min[1])
	{
		if (s->data[1] == min[0])
			exec_instration(s, NULL, SA, PRINT_ON);
		else
			exec_instration(s, NULL, RRA, PRINT_ON);
	}
	else
	{
		if (s->data[1] == min[0])
			exec_instration(s, NULL, RA, PRINT_ON);
		else if (s->data[1] == min[1])
		{
			exec_instration(s, NULL, SA, PRINT_ON);
			exec_instration(s, NULL, RRA, PRINT_ON);
		}
	}
}

static void	sort_4(t_stack *sa, t_stack *sb)
{
	int	min[2];

	min[0] = get_next_min(sa, INT_MIN);
	min[1] = get_next_min(sa, min[0]);
	while (!is_sorted(sa))
	{
		if (sa->data[0] == min[0])
			exec_instration(sa, sb, PB, PRINT_ON);
		else if (sa->size == 3 && !is_sorted(sa))
		{
			min[0] = get_next_min(sa, INT_MIN);
			min[1] = get_next_min(sa, min[0]);
			sort_3(min, sa);
		}
		else
			exec_instration(sa, sb, RA, PRINT_ON);
	}
	while (sb->size)
		exec_instration(sa, sb, PA, PRINT_ON);
}

static void	sort_5(t_stack *sa, t_stack *sb)
{
	int	min[2];

	min[0] = get_next_min(sa, INT_MIN);
	min[1] = get_next_min(sa, min[0]);
	while (!is_sorted(sa))
	{
		if (sa->data[0] == min[0] || sa->data[0] == min[1])
			exec_instration(sa, sb, PB, PRINT_ON);
		else if (sa->size == 3 && !is_sorted(sa))
		{
			min[0] = get_next_min(sa, INT_MIN);
			min[1] = get_next_min(sa, min[0]);
			sort_3(min, sa);
		}
		else
			exec_instration(sa, sb, RA, PRINT_ON);
	}
	while (sb->size)
		exec_instration(sa, sb, PA, PRINT_ON);
	if (!is_sorted(sa))
		exec_instration(sa, sb, SA, PRINT_ON);
}

void	main_sort_min(t_stack *sa, t_stack *sb)
{
	int	min[2];

	min[0] = get_next_min(sa, INT_MIN);
	min[1] = get_next_min(sa, min[0]);
	if (sa->size == 2)
		exec_instration(sa, NULL, SA, PRINT_ON);
	else if (sa->size == 3)
		sort_3(min, sa);
	else if (sa->size == 4)
		sort_4(sa, sb);
	else if (sa->size == 5)
		sort_5(sa, sb);
}
