/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beakduma <beakduma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 06:58:58 by beakduma          #+#    #+#             */
/*   Updated: 2026/09/26 02:16:40 by beakduma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive (t_stack **a, t_stack **b, int count)
{
	if (compute_disorder (&a, count) < 0.2)
		sort_simple(&a, &b, count);
	else if (compute_disorder (&a, count) < 0.5)
		sort_medium ();
	else
		sort_complex ();
}
