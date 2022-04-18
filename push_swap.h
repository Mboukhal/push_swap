/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboukhal <mboukhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:51:09 by mboukhal          #+#    #+#             */
/*   Updated: 2022/04/18 16:21:44 by mboukhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

typedef struct stacks
{
	int	*data;
	int	size;
	int	size_max;
}t_stack;

//              utiles
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

//              stack operations
void	ft_pop(t_stack *s, int *poped);
void	ft_push(t_stack *s, int *push);
void	ft_shift_down(t_stack *s);
void	ft_shift_up(t_stack *s);
void	ft_swap_int(int *a, int *b);

//              check and initialisation
t_stack	*init_stack(int *stack, int size, int status);
int		*check_av(char **av, int size);
int		*cheak_set_cotes(int *size, char *cote);
t_stack	*stack_to_list(int *st, int size);
void	cheak_arg(char *av, int size);
int		valid_cote(char *str);
void	check_all(char **str, int *stack_in, int size, int status);
int		*set_stack(char **numbers, int size);
int		cheak_isint(char **args);
int		cheak_isdup(int *stack, int size);
int		cheak_limit(char **args);
void	sort_stack(int *stack, int size);

//              sorting
void	stack_to_index(t_stack *s);
void	main_sort_min(t_stack *sa, t_stack *sb);
void	main_sort_big(t_stack *sa, t_stack *sb);
int		is_sorted(t_stack *s);

//              instractions
void	exec_instration(t_stack *sa, t_stack *sb, int ins, int print);
void	print_ins(int ins);
# define PRINT_ON		1
# define PRINT_OFF		0

void	ra_rb_rr(t_stack *sa, t_stack *sb, int status);
# define RA     2
# define RB     3
# define RR     4

void	rra_rrb_rrr(t_stack *sa, t_stack *sb, int status);
# define RRA     5
# define RRB     6
# define RRR     7

void	sa_sb_ss(t_stack *sa, t_stack *sb, int status);
# define SA     8
# define SB     9
# define SS     10

void	pa_pb(t_stack *sa, t_stack *sb, int status);
# define PA     11
# define PB     12

//				checker
void	sort_stack_checker(int *stack, int size);

#endif // PUSH_SWAP_H
