/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:58:53 by oelharbi          #+#    #+#             */
/*   Updated: 2024/02/20 23:42:13 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

int	check_sign(char *str)
{
	int	sign;

	sign = 1;
	if (!ft_isdigit(*(str + 1)))
		return_error();
	if (*str == '-')
		sign = -1;
	return (sign);
}

int	ft_atol(char *str, int sign)
{
	long	result;
	int		check;

	result = 0;
	while (*str == ' ' )
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = check_sign(str);
		str++;
	}
	while (*str)
	{
		check = result;
		if (!(*str >= 48 && *str <= 57))
			return_error();
		result = result * 10 + (*str - 48);
		if (result / 10 != check)
			return_error();
		str++;
	}
	if ((sign * result) > INT_MAX || (sign * result) < INT_MIN)
		return_error();
	return (sign * result);
}

int	handle_duplicate_error(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	current = *stack;
	tmp = NULL;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free (current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_errors(t_stack **stack)
{
	free_stack(stack);
	return_error();
}
