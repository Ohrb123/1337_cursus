/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:17:09 by oelharbi          #+#    #+#             */
/*   Updated: 2024/02/11 22:30:53 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack **stack_a, int i)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (!*stack_a || !((*stack_a)->next))
		return ;
	tmp = lstlast(*stack_a);
	prev = *stack_a;
	while (prev->next != tmp)
		prev = prev->next;
	prev->next = NULL;
	tmp->next = *stack_a;
	*stack_a = tmp;
	if (i == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, int i)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (!*stack_b || !((*stack_b)->next))
		return ;
	tmp = lstlast(*stack_b);
	prev = *stack_b;
	while (prev->next != tmp)
		prev = prev->next;
	prev->next = NULL;
	tmp->next = *stack_b;
	*stack_b = tmp;
	if (i == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int i)
{
	if (!stack_a || !stack_b || !(*stack_a)->next || !(*stack_b)->next)
		return ;
	rra(stack_a, 1);
	rrb(stack_b, 1);
	if (i == 0)
		write(1, "rrr\n", 4);
}
