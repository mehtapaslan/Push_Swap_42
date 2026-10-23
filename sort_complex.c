/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mehaslan <mehaslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 06:58:48 by beakduma          #+#    #+#             */
/*   Updated: 2026/10/23 22:45:48 by mehaslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void index_stack(t_stack *a, int size)
{
    t_stack *copy;
    
    copy = copy_stack(a, size);
    if (!copy)
		return ;
    selection_sort(copy, size);
	assign_index(a, copy, size);
	free_stack(&copy);
}

t_stack *selection_sort(t_stack *arr, int size)
{
    t_stack *current_arr;
    t_stack *temp_arr;
    int	remaining;
	int	min_index;
    int temp;
	
    current_arr = arr;
    remaining = size;
	while (remaining > 1)
	{
		min_index = find_minimum (current_arr, remaining);
        temp_arr = current_arr;
		while(min_index--)
            temp_arr = temp_arr->next;
        temp = current_arr->value; 
        current_arr->value = temp_arr->value;
        temp_arr->value = temp;
        current_arr = current_arr->next;
		remaining--;
	}
    return(arr);
}