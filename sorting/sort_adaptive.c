/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beakduma <beakduma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 06:58:58 by beakduma          #+#    #+#             */
/*   Updated: 2026/11/15 18:40:44 by beakduma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_stack **a, t_stack **b, int count)
{
	double	disorder;

	disorder = compute_disorder(a, count);
	if (count <= 5 || disorder < 0.2)
		sort_simple(a, b, count);
	else if (disorder < 0.5)
		sort_medium(a, b, count);
	else
		sort_complex(a, b, count);
}

void	sort_stack(t_stack **a, t_stack **b, t_strategy strategy, int count)
{
	if (strategy == STR_SIMPLE)
		sort_simple(a, b, count);
	else if (strategy == STR_MEDIUM)
		sort_medium(a, b, count);
	else if (strategy == STR_COMPLEX)
		sort_complex(a, b, count);
	else
		sort_adaptive(a, b, count);
}
