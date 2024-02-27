/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_custom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:59:07 by oelharbi          #+#    #+#             */
/*   Updated: 2024/02/16 18:19:52 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//CASES
// "1 3 2" |  "3 1 2" | "3 2 1" | "2 1 3" | "2 3 1"
void	sort_three(t_stack **stack_a)
{
	if (if_sorted(*stack_a))
		return ;
	if (find_smallest(*stack_a) == (*stack_a)->nbr)
	{
		sa(stack_a, 0);
		ra(stack_a, 0);
	}
	else if (find_biggest(*stack_a) == (*stack_a)->nbr)
	{
		ra(stack_a, 0);
		if (!if_sorted((*stack_a)))
			sa(stack_a, 0);
	}
	else
	{
		if (find_index(*stack_a, find_biggest(*stack_a)) == 2)
			sa(stack_a, 0);
		else
			rra(stack_a, 0);
	}
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	if (if_sorted(*stack_a))
		return ;
	if (find_index(*stack_a, find_smallest(*stack_a)) == 0)
		pb(stack_a, stack_b, 0);
	else if (find_index(*stack_a, find_smallest(*stack_a)) == 1)
	{
		sa(stack_a, 0);
		pb(stack_a, stack_b, 0);
	}
	else
	{
		while (find_index(*stack_a, find_smallest(*stack_a)) != 0)
			rra(stack_a, 0);
		pb(stack_a, stack_b, 0);
	}
	sort_three(stack_a);
	pa(stack_a, stack_b, 0);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	if (if_sorted(*stack_a))
		return ;
	if (find_index(*stack_a, find_smallest(*stack_a)) == 0)
		pb(stack_a, stack_b, 0);
	else if (find_index(*stack_a, find_smallest(*stack_a)) == 1)
	{
		sa(stack_a, 0);
		pb(stack_a, stack_b, 0);
	}
	else
	{
		while (find_index(*stack_a, find_smallest(*stack_a)) != 0)
			rra(stack_a, 0);
		pb(stack_a, stack_b, 0);
	}
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b, 0);
}

void	use_abs(t_stack **stack_a, t_stack **stack_b, \
				t_helpers helpers, t_stack *previous_max)
{
	if (absolute_value(*stack_b, helpers.max_index)
		< absolute_value(*stack_b, helpers.previous_max_index))
	{
		move(stack_b, &previous_max, helpers.previous_max_index);
		pa(stack_a, stack_b, 0);
		if (!stack_b)
			return ;
	}
}

void	sort_hundreds(t_stack **stack_a, t_stack **stack_b)
{
	t_helpers	helpers;
	t_stack		*max;
	t_stack		*previous_max;

	max = NULL;
	previous_max = NULL;
	set_helpers(&helpers, *stack_a);
	fill_b(stack_a, stack_b, helpers);
	while (*stack_b)
	{
		max = find_max(stack_b);
		previous_max = find_previous_max(stack_b);
		helpers.max_index = find_index(*stack_b, max->nbr);
		helpers.previous_max_index = find_index(*stack_b, previous_max->nbr);
		use_abs(stack_a, stack_b, helpers, previous_max);
		helpers.max_index = find_index(*stack_b, max->nbr);
		move(stack_b, &max, helpers.max_index);
		pa(stack_a, stack_b, 0);
		if ((*stack_a)->next && \
		(*stack_a)->next->position < (*stack_a)->position)
			sa(stack_a, 0);
	}
}
