/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 11:15:15 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/18 16:33:46 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int	size;
	int	*stack;

	size = ac - 1;
	stack = check_av(av, size);
	sort_stack_checker(stack, size);
	return (EXIT_SUCCESS);
}
