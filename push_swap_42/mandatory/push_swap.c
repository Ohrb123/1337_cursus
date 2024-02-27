/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:56:28 by oelharbi          #+#    #+#             */
/*   Updated: 2024/02/20 23:19:07 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	if (lstsize(*stack_a) == 2)
		sa(stack_a, 0);
	else if (lstsize(*stack_a) == 3)
		sort_three(stack_a);
	else if (lstsize(*stack_a) == 4)
		sort_four(stack_a, stack_b);
	else if (lstsize(*stack_a) == 5)
		sort_five(stack_a, stack_b);
	else
		sort_hundreds(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc >= 2)
	{
		if (argc == 2 && !argv[1][0])
			print_error();
		stack_a = parse(argc, argv);
		if (!stack_a || handle_duplicate_error(stack_a))
			free_errors(&stack_a);
		if (!if_sorted(stack_a))
			sort(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	return (0);
}
