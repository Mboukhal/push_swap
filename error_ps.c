/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 13:07:05 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/04 15:35:12 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
                    // comper whit INT_MAX and INT_MIN
                    // -2147483648 2147483647
static int comper_str(char *str)
{
    char    *max;
    int     sign;
    int     index;
    
    max = ft_itoa(INT_MAX);
    index = 0;
    sign = 0;
    while (str[index])
    {
        if (str[index] == '-' && index == 0)
            sign++;
        if (str[index] == '+' && index == 0)
            sign++;
        if (str[index + sign] > max[index])
        {
            if (str[0] == '-' && index == 9 && str[index + sign] == '8')
                break ;
            return (EXIT_FAILURE);
        }
        index++;
    }
    free(max);
    return (EXIT_SUCCESS);
}
int    cheak_limit(char **args)
{
    int iter;
    int len;

    iter = 0;
    while (args[iter])
    {
        len = ft_strlen(args[iter]);
        if (len > 9)
        {
            if (len > 11 || comper_str(args[iter]))
            {
                ft_putstr_fd("Error\n\tvalue [", STDERR_FILENO);
                ft_putstr_fd(args[iter], STDERR_FILENO);
                ft_putstr_fd("] index [", STDERR_FILENO);
                ft_putnbr_fd(iter, STDERR_FILENO);
                ft_putstr_fd("] not in integer range !!\n", STDERR_FILENO);
                return(EXIT_FAILURE);
            }
        }
        iter++;
    }
    return(EXIT_SUCCESS);
}

                // isnumber && isint
int  cheak_isint(char **args)
{
    int i;
    int j;

    i = 0;
    while (args[i])
    {
        j = 0;
        while (args[i][j])
        {
            if ((args[i][j] == '-' || args[i][j] == '+') && j == 0)
                j++;
            if (!ft_isdigit(args[i][j]))
            {
                ft_putstr_fd("Error\n\tvalue [", STDERR_FILENO);
                ft_putstr_fd(args[i], STDERR_FILENO);
                ft_putstr_fd("] index [", STDERR_FILENO);
                ft_putnbr_fd(i, STDERR_FILENO);
                ft_putstr_fd("] not integer !!\n", STDERR_FILENO);
                return(EXIT_FAILURE);
            }
            j++;
        }
        i++;
    }
    return(EXIT_SUCCESS);
}
                    // duplicate
int    cheak_isdup(int *stack, int size)
{
    int iter;
    int index;

    iter = 0;
    while (iter != size )
    {
        index = iter + 1;
        while (index != size )
        {
            if (stack[index] == stack[iter])
            {
                ft_putstr_fd("Error\n\t[", STDERR_FILENO);
                ft_putnbr_fd(stack[index], STDERR_FILENO);
                ft_putstr_fd("] index [", STDERR_FILENO);
                ft_putnbr_fd(index, STDERR_FILENO);
                ft_putstr_fd("] and [", STDERR_FILENO);
                ft_putnbr_fd(iter, STDERR_FILENO);
                ft_putstr_fd("] duplicated number !!\n", STDERR_FILENO);
                return(EXIT_FAILURE);
            }
            index++;
        }
        iter++;
    }
    return(EXIT_SUCCESS);
}
