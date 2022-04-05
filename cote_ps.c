/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cote_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 22:02:59 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/04 15:30:49 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    valid_cote(char *str)
{
    int iter;

    iter = 0;
    while (str[iter])
    {
        if (!(str[iter] == ' ' || str[iter] == '-' ||
            (str[iter] <= '9' && str[iter] >= '0')) )
            cheak_isint(&str);
        iter++;
    }
    return (0);
}

void    check_all(char **str, int *stack_in, int size, int status)
{
    int result;
    int i;

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
}