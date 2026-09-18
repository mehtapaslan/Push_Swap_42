/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehaslan <mehaslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/17 16:42:40 by mehaslan          #+#    #+#             */
/*   Updated: 2026/09/19 00:35:41 by mehaslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
