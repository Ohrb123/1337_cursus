/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:46:59 by oelharbi          #+#    #+#             */
/*   Updated: 2024/02/20 23:42:39 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

t_stack	*init_stack_a(int argc, char **spl, t_stack *a, char **argv)
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
			return_error();
		if (*argv[argc - 1] == '\0' || *spl == NULL)
			return_error();
		while (spl[i])
		{
			nbr = ft_atol(spl[i], 1);
			free(spl[i]);
			ft_lstadd_back(&a, ft_lstnew(nbr, 0));
			i++;
		}
		free(spl);
		j++;
	}
	return (a);
}

t_stack	*parse(int argc, char **argv)
{
	t_stack	*a;
	char	**spl;

	spl = NULL;
	a = NULL;
	a = init_stack_a(argc, spl, a, argv);
	return (a);
}
