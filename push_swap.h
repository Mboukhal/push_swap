/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:51:09 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/02 15:34:33 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

        // cheak parmeter if numbers in double cote
void    cheak_arg(char *av, int size);
int     valid_cote(char *str);
void    check_all(char **str, int *stack_in, int size);

int     *set_stack(char **numbers, int size);
void    cheak_isint(char **args);
void    cheak_isdup(int *stack,int size);
void    cheak_limit(char **args);
void    sort_stack(int *stack_a, int *stack_b);
void    sa(int *stack);


#endif // PUSH_SWAP_H