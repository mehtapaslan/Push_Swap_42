/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beakduma <beakduma@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 04:18:19 by beakduma          #+#    #+#             */
/*   Updated: 2026/09/21 03:21:47 by beakduma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack *create_node(int value)
{
	t_stack *node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	return (node);
}

static void append_node(t_stack **head, t_stack **last, t_stack *new_node)
{
	if (!*head)
	{
		*head = new_node;
		new_node->prev = new_node;
		new_node->next = new_node;
	}
	else
	{
		new_node->prev = *last;
		new_node->next = *head;
		(*last)->next = new_node;
		(*head)->prev = new_node;
	}
	*last = new_node;
}

t_stack *build_stack(int *numbers, int count)
{
	t_stack *head;
	t_stack *new_node;
	t_stack *last;
	int i;

	head = NULL;
	last = NULL;
	i = 0;

	while (i < count)
	{
		new_node = create_node(numbers[i]);
		if (!new_node)
		{
			free_stack(&head);
			return (NULL);
		}
		append_node(&head, &last, new_node);
		i++;
	}
	return (head);
}

void free_stack(t_stack **stack)
{
	t_stack *current;
	t_stack *next_node;

	if (!stack || !*stack)
		return ;
	(*stack)->prev->next = NULL;
	current = *stack;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*stack = NULL;
}
