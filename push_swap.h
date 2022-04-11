/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:51:09 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/07 01:35:17 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define SA     0
# define SB     1
# define SS     2

# define PA     0
# define PB     1

# define RA     0
# define RB     1
# define RR     2

# define RRA     0
# define RRB     1
# define RRR     2

                        /*
                         *      index[0] first address of list
                         *      index[1] last address of list
                         *      size of stack (count betwin index[0] and index[1])
                         */
typedef struct stacks
{
        int             stack;
        struct stacks   *next;

}               t_stack;

/********************** TORM:*********************/

# include <stdio.h>
void    p_stack(int *stack, int count);
void    p_loop(t_stack *s);
/*************************************************/


int     ft_pop(t_stack *s);
void    ft_push(t_stack *s, int data);
void    ft_shift_down(t_stack *s);
void    ft_shift(t_stack *s);
void    ft_swap_head_stack(t_stack *s);

t_stack *stack_to_list(int *st, int size);
// t_stack *cp_stack(int *st, int size);//, t_stack *data);
void    cheak_arg(char *av, int size);
int     valid_cote(char *str);
void    check_all(char **str, int *stack_in, int size, int status);

int     *set_stack(char **numbers, int size);
int     cheak_isint(char **args);
int     cheak_isdup(int *stack,int size);
int     cheak_limit(char **args);
void    sort_stack(int *stack, int size);

// void    ra_rb_rr(t_stack *sa,t_stack *sb, int status);
// void    rra_rrb_rrr(t_stack *sa,t_stack *sb, int status);
// void    sa_sb_ss(t_stack *sa, t_stack *sb, int status);
// void    pa_pb(t_stack *sa, t_stack *sb, int status);

#endif // PUSH_SWAP_H