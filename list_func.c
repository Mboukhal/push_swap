/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:51:46 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/19 01:26:32 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_int(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_pop(t_stack *s, int *poped)
{
	int	i;

	if (s->size == 0)
		return ;
	*poped = s->data[0];
	s->size--;
	i = 0;
	while (i <= s->size)
	{
		s->data[i] = s->data[i + 1];
		i++;
	}
}

void	ft_shift_down(t_stack *s)
{
	int	i;
	int	tmp;

	if (s->size < 1)
		return ;
	tmp = s->data[s->size - 1];
	i = s->size;
	while (i > 0)
	{
		s->data[i] = s->data[i - 1];
		i--;
	}
	s->data[0] = tmp;
}

void	ft_push(t_stack *s, int *push)
{
	int	i;
	int	*tmp;

	if (s->size_max <= s->size)
		return ;
	tmp = malloc(sizeof(int) * (s->size + 2));
	i = 0;
	while (i <= s->size)
	{
		tmp[i + 1] = s->data[i];
		i++;
	}
	s->size++;
	s->data[0] = *push;
	i = 1;
	while (i < s->size)
	{
		s->data[i] = tmp[i];
		i++;
	}
	free(tmp);
}

void	ft_shift_up(t_stack *s)
{
	int	i;
	int	tmp;

	if (s->size <= 1)
		return ;
	if (s->size == 2)
	{
		ft_swap_int(&s->data[0], &s->data[1]);
		return ;
	}
	tmp = s->data[0];
	i = -1;
	while (i++ < s->size)
		s->data[i] = s->data[i + 1];
	s->data[i - 2] = tmp;
}
