/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 01:03:06 by oelharbi          #+#    #+#             */
/*   Updated: 2024/02/20 23:43:33 by oelharbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H  

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				nbr;
	int				position;
	struct s_stack	*next;
}	t_stack;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif

//Errors and Parsing

void	return_error(void);
int		handle_duplicate_error(t_stack *stack_a);
t_stack	*parse(int argc, char **argv);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstnew(int nbr, int position);
int		ft_lstsize(t_stack *lst);
void	free_stack(t_stack **stack);
void	free_errors(t_stack **stack);
int		ft_atol(char *str, int sign);
int		if_sorted(t_stack *stack_a);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*init_stack_a(int argc, char **spl, t_stack *a, char **argv);
char	**ft_split(const char *s, char c);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
int		my_strlen(const char *s);
int		ft_isdigit(int c);
void	*ft_free(char **s);

//moves

void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

//checker 

int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_checker(t_stack **stack_a, t_stack **stack_b);
int		find_move(char **move, char *str);

//get_next_line

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *buff);
size_t	ft_strlen(const char *s);
char	*print_the_line(char *line);
char	*rest_line(char *line);
char	*get_the_line(char	*str, int fd);
char	*get_next_line(int fd);
char	*ft_strdup(char *str);

#endif