/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:46:59 by oelharbi          #+#    #+#             */
/*   Updated: 2024/02/20 23:39:46 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*init_stack_a(int argc, char **spl, t_stack *stack_a, char **argv)
{
	int	i;
	int	j;
	int	nbr;

	i = 0;
	j = 1;
	while (j < argc)
	{
		i = 0;
		spl = ft_split(argv[j], ' ');
		if (!spl)
			print_error();
		if (*argv[argc - 1] == '\0' || *spl == NULL)
			print_error();
		while (spl[i])
		{
			nbr = ft_atol(spl[i], 1);
			free(spl[i]);
			lstadd_back(&stack_a, lstnew(nbr, 0));
			i++;
		}
		free(spl);
		j++;
	}
	return (stack_a);
}

t_stack	*parse(int argc, char **argv)
{
	t_stack	*stack_a;
	char	**spl;

	spl = NULL;
	stack_a = NULL;
	stack_a = init_stack_a(argc, spl, stack_a, argv);
	return (stack_a);
}
