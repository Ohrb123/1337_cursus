/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:04:27 by oelharbi          #+#    #+#             */
/*   Updated: 2024/02/16 19:00:35 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;
	t_stack	*tmp;
	int		index;

	tmp = *lst;
	index = 0;
	if (!lst || !new)
		return ;
	while (tmp)
	{
		if (tmp->nbr > new->nbr)
			tmp->position++;
		else
			new->position++;
		tmp = tmp->next;
	}
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = lstlast(*lst);
	last->next = new;
}

t_stack	*lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst -> next;
	return (lst);
}

t_stack	*lstnew(int nbr, int position)
{
	t_stack	*head;

	head = malloc(sizeof(t_stack));
	if (!head)
		print_error();
	head->nbr = nbr;
	head->position = position;
	head->next = NULL;
	return (head);
}

int	lstsize(t_stack *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	print_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}
