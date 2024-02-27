/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 22:46:00 by oelharbi          #+#    #+#             */
/*   Updated: 2024/02/17 15:50:20 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	there_is_more(t_stack *stack_a, int chunk)
{
	while (stack_a)
	{
		if (stack_a->position < chunk)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	set_helpers(t_helpers *helpers, t_stack *stack_a)
{
	helpers->stack_size = lstsize(stack_a);
	if (helpers->stack_size >= 200)
		helpers->devide_by = 9;
	else
		helpers->devide_by = 5;
	helpers->chunk = helpers->stack_size / helpers->devide_by;
}

void	fill_b(t_stack **stack_a, t_stack **stack_b, t_helpers helpers)
{
	while (*stack_a)
	{
		if ((*stack_a)->position < helpers.chunk)
		{
			pb(stack_a, stack_b, 0);
			if (!*stack_a)
				return ;
			if ((*stack_b)->position >= \
			helpers.chunk - (helpers.stack_size / helpers.devide_by) / 2)
			{
				if (there_is_more(*stack_a, helpers.chunk) && \
				(*stack_a)->position >= helpers.chunk)
					rr(stack_a, stack_b, 0);
				else
					rb(stack_b, 0);
			}
		}
		else
			ra(stack_a, 0);
		if (!there_is_more(*stack_a, helpers.chunk))
			helpers.chunk += helpers.stack_size / helpers.devide_by;
	}
}
