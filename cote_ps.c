/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cote_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 22:02:59 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/18 16:23:28 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_cote(char *str)
{
	int	iter;

	iter = 0;
	while (str[iter])
	{
		if (!(str[iter] == ' ' || str[iter] == '-'
				|| (str[iter] <= '9' && str[iter] >= '0')))
			cheak_isint(&str);
		iter++;
	}
	return (0);
}

static void	check_sorted(int size, int *stack)
{
	int	i;

	i = 0;
	while (i++ <= size)
		if (stack[i - 1] > stack[i])
			break ;
	if (i == size)
		exit (EXIT_FAILURE);
}

void	check_all(char **str, int *stack_in, int size, int status)
{
	int	result;
	int	i;

	result = EXIT_SUCCESS;
	result = cheak_isint(str);
	if (result == EXIT_SUCCESS)
		result = cheak_limit(str);
	if (result == EXIT_SUCCESS)
		result = cheak_isdup(stack_in, size);
	if (status == 1 && result == EXIT_FAILURE)
	{
		i = 0;
		while (str[i])
			free(str[i++]);
		free(str);
		exit (EXIT_FAILURE);
	}
	if (status == 0 && result == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	check_sorted(size, stack_in);
}

int	*cheak_set_cotes(int *size, char *cote)
{
	char	**str;
	int		i;
	int		*stack;

	str = ft_split(cote, ' ');
	*size = 0;
	while (str[(*size)])
		(*size)++;
	stack = set_stack(str, (*size));
	check_all(str, stack, (*size), 1);
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (stack);
}

int	*check_av(char **av, int size)
{
	int		*stack_in;

	if (size < 1)
		exit (EXIT_FAILURE);
	else if (size == 1)
		stack_in = cheak_set_cotes(&size, av[1]);
	else
	{
		stack_in = set_stack(&av[1], size);
		check_all(&av[1], stack_in, size, 0);
	}
	return (stack_in);
}
