/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:10:09 by oelharbi          #+#    #+#             */
/*   Updated: 2024/02/15 21:38:53 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_biggest(t_stack *stack)
{
	int	i;

	i = stack->nbr;
	while (stack)
	{
		if (i < stack->nbr)
			i = stack->nbr;
		stack = stack->next;
	}
	return (i);
}

int	find_smallest(t_stack *stack)
{
	int	i;

	i = stack->nbr;
	while (stack)
	{
		if (i > stack->nbr)
			i = stack->nbr;
		stack = stack->next;
	}
	return (i);
}

int	find_index(t_stack *stack, int nbr)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->nbr == nbr)
			return (i);
		stack = stack->next;
		i++;
	}
	return (0);
}

int	if_sorted(t_stack *stack_a)
{
	int	num;

	num = stack_a->nbr;
	while (stack_a)
	{
		if (num > stack_a->nbr)
			return (0);
		num = stack_a->nbr;
		stack_a = stack_a->next;
	}
	return (1);
}
