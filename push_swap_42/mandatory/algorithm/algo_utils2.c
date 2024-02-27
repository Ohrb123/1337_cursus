/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:45:57 by oelharbi          #+#    #+#             */
/*   Updated: 2024/02/14 22:52:25 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	absolute_value(t_stack *stack, int max)
{
	int	abs;

	abs = (lstsize(stack) / 2) - max;
	if (abs < 0)
		return (-abs);
	else
		return (abs);
}

t_stack	*find_max(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*big;

	big = *stack;
	tmp = (*stack)->next;
	while (tmp)
	{
		if (tmp->nbr > big->nbr)
			big = tmp;
		tmp = tmp->next;
	}
	return (big);
}

t_stack	*find_previous_max(t_stack **stack)
{
	t_stack	*next_max;
	t_stack	*max;
	t_stack	*tmp;

	max = find_max(stack);
	next_max = NULL;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->position < max->position)
		{
			if (next_max == NULL || tmp->position > next_max->position)
				next_max = tmp;
		}
		tmp = tmp->next;
	}
	if (next_max == NULL)
		return (*stack);
	else
		return (next_max);
}

void	move(t_stack **stack_b, t_stack **max, int index)
{
	if (index < lstsize(*stack_b) / 2)
	{
		while (*stack_b != *max)
			rb(stack_b, 0);
	}
	else
	{
		while (*stack_b != *max)
			rrb(stack_b, 0);
	}
}
