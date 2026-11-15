/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehaslan <mehaslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:42:40 by mehaslan          #+#    #+#             */
/*   Updated: 2026/11/15 04:07:34 by mehaslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef enum e_strategy
{
	STR_NONE,
	STR_ADAPTIVE,
	STR_SIMPLE,
	STR_MEDIUM,
	STR_COMPLEX
}	t_strategy;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}	t_op;

typedef struct s_data
{
	int			*numbers;
	int			count;
	int			is_bench;
	t_strategy	strategy;
}	t_data;

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	parse_args(int argc, char **argv, t_data *data);
void	control_flags(char *str, t_data *data);
void	control_numbers(char *str, t_data *data);
void	init_data(t_data *data);
int		is_valid_numbers(char *str);
int		is_duplicate(int *nbrs, int count, int nbr);
int		add_nbr(t_data *data, int nbr);
int		atoi_safety(const char *nptr, int *result);
void	error_exit(t_data *data, char **args);
void	free_data(t_data *data);
void	free_args(char **args);
int		is_sorted(int *nbrs, int count);
void	set_strategy(char *str, t_data *data);
t_stack	*build_stack(int *numbers, int count);
t_stack	*copy_stack(t_stack *stack, int count);
void	free_stack(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
double	compute_disorder(t_stack **a, int count);
int		find_minimum(t_stack *a, int size);
void	sort_simple(t_stack **a, t_stack **b, int count);
void	sort_medium(t_stack **a, t_stack **b, int count);
void	sort_complex(t_stack **a, t_stack **b, int size);
void	selection_sort(t_stack *arr, int size);
void	assign_index(t_stack *a, t_stack *copy, int size);
int		index_stack(t_stack *a, int size);
int		get_max_bits(int size);
void	sort_adaptive(t_stack **a, t_stack **b, int count);
void	sort_stack(t_stack **a, t_stack **b, t_strategy strategy, int count);
void	rank_stack(t_stack *a, int size);
int		chunk_count(int size);
void	rotate_a_by(t_stack **a, int moves);
void	rotate_b_by(t_stack **b, int moves);
int		find_index_pos(t_stack *b, int target);
int		*op_counts(void);
char	*op_name(t_op op);
void	put_op(t_op op);
void	print_bench(t_strategy strategy, double disorder);

#endif
