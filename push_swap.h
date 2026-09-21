/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehaslan <mehaslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:42:40 by mehaslan          #+#    #+#             */
/*   Updated: 2026/09/21 15:16:58 by mehaslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "./libft/libft.h"

typedef enum e_strategy
{
  STR_ADAPTIVE,
  STR_SIMPLE,
  STR_MEDIUM,
  STR_COMPLEX
} t_strategy;

typedef struct s_data
{
    int *numbers;
    int count;
    int is_bench;
    t_strategy strategy;
} t_data;

typedef struct s_stack
{
    int              value;
    int              index;
    struct s_stack   *next;
    struct s_stack   *prev;
} t_stack;

void	parse_args(int argc, char **argv, t_data *data);
void	control_flags(char *str, t_data *data);
void	control_numbers(char *str, t_data *data);
void	init_data(t_data *data);
int		is_valid_numbers(char *str);
int		is_duplicate(int *nbrs, int count, int nbr);
int		add_nbr(t_data *data, int nbr);
long	atolong(const char *nptr);