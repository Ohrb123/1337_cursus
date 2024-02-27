/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 00:59:42 by oelharbi          #+#    #+#             */
/*   Updated: 2024/02/20 22:14:22 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	if_sorted(t_stack *stack_a)
{
	int	num;

	if (!stack_a)
		return (0);
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

int	find_move(char **move, char *str)
{
	int	index;

	index = 0;
	while (move[index])
	{
		if (!ft_strncmp(move[index], str, my_strlen(move[index]) + 1))
			return (index);
		index++;
	}
	return (-1);
}

void	do_the_move(t_stack **stack_a, t_stack **stack_b, int index)
{
	if (index == 0)
		sa(stack_a);
	else if (index == 1)
		sb(stack_b);
	else if (index == 2)
		ss(stack_a, stack_b);
	else if (index == 3)
		pa(stack_a, stack_b);
	else if (index == 4)
		pb(stack_a, stack_b);
	else if (index == 5)
		ra(stack_a);
	else if (index == 6)
		rb(stack_b);
	else if (index == 7)
		rr(stack_a, stack_b);
	else if (index == 8)
		rra(stack_a);
	else if (index == 9)
		rrb(stack_b);
	else if (index == 10)
		rrr(stack_a, stack_b);
}

void	ft_checker(t_stack **stack_a, t_stack **stack_b)
{
	char		*str;
	char		**move;
	int			index;
	char		*string;

	str = NULL;
	string = "sa\n sb\n ss\n pa\n pb\n ra\n rb\n rr\n rra\n rrb\n rrr\n";
	move = ft_split(string, ' ');
	if (move == NULL)
		return ;
	while (1)
	{
		str = get_next_line(0);
		if (!str || str[0] == '\0')
			break ;
		index = find_move(move, str);
		free(str);
		if (index == -1)
		{
			(ft_free(move), return_error());
		}
		do_the_move(stack_a, stack_b, index);
	}
	free(str);
	ft_free(move);
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
			return_error();
		stack_a = parse(argc, argv);
		if (!stack_a || handle_duplicate_error(stack_a))
			free_errors(&stack_a);
		ft_checker(&stack_a, &stack_b);
		if (if_sorted(stack_a) && !stack_b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
