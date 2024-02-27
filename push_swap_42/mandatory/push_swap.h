/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:57:35 by oelharbi          #+#    #+#             */
/*   Updated: 2024/02/20 23:40:57 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H  

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	long				nbr;
	int					position;
	int					index;
	struct s_stack		*next;
}	t_stack;

typedef struct s_helpers
{
	int	chunk;
	int	devide_by;
	int	stack_size;
	int	max_index;
	int	previous_max_index;
}	t_helpers;

//Errors and Parsing

void	print_error(void);
int		handle_duplicate_error(t_stack *stack_a);
t_stack	*parse(int argc, char **argv);
void	lstadd_back(t_stack **lst, t_stack *new);
t_stack	*lstlast(t_stack *lst);
t_stack	*lstnew(int nbr, int position);
int		lstsize(t_stack *lst);
void	free_stack(t_stack **stack);
void	free_errors(t_stack **stack);
int		ft_atol(char *str, int sign);
char	**ft_split(const char *s, char c);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
int		ft_strlen(const char *s);
int		ft_isdigit(int c);

//moves

void	sa(t_stack **stack_a, int i);
void	sb(t_stack **stack_b, int i);
void	ss(t_stack **stack_a, t_stack **stack_b, int i);
void	ra(t_stack **stack_a, int i);
void	rb(t_stack **stack_b, int i);
void	rr(t_stack **stack_a, t_stack **stack_b, int i);
void	rra(t_stack **stack_a, int i);
void	rrb(t_stack **stack_b, int i);
void	rrr(t_stack **stack_a, t_stack **stack_b, int i);
void	pa(t_stack **stack_a, t_stack **stack_b, int i);
void	pb(t_stack **stack_a, t_stack **stack_b, int i);

//algorithm

void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort_hundreds(t_stack **stack_a, t_stack **stack_b);
int		if_sorted(t_stack *stack_a);
int		find_biggest(t_stack *stack);
int		find_smallest(t_stack *stack);
void	sort_three(t_stack **stack_a);
int		find_index(t_stack *stack, int nbr);
int		absolute_value(t_stack *stack, int max);
void	move(t_stack **stack_b, t_stack **max, int index);
void	set_helpers(t_helpers *helpers, t_stack *stack_a);
void	fill_b(t_stack **stack_a, t_stack **stack_b, t_helpers helpers);
int		there_is_more(t_stack *stack_a, int chunk);
t_stack	*find_max(t_stack **stack);
t_stack	*find_previous_max(t_stack **stack);
void	use_abs(t_stack **stack_a, t_stack **stack_b, \
t_helpers helpers, t_stack *previous_max);
t_stack	*init_stack_a(int argc, char **spl, t_stack *a, char **argv);

#endif