/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 21:17:09 by oelharbi          #+#    #+#             */
/*   Updated: 2024/02/16 21:16:25 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	rra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (!*stack_a || !((*stack_a)->next))
		return ;
	tmp = ft_lstlast(*stack_a);
	prev = *stack_a;
	while (prev->next != tmp)
		prev = prev->next;
	prev->next = NULL;
	tmp->next = *stack_a;
	*stack_a = tmp;
}

void	rrb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (!*stack_b || !((*stack_b)->next))
		return ;
	tmp = ft_lstlast(*stack_b);
	prev = *stack_b;
	while (prev->next != tmp)
		prev = prev->next;
	prev->next = NULL;
	tmp->next = *stack_b;
	*stack_b = tmp;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
