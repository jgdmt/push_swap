/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:43:52 by jgoudema          #+#    #+#             */
/*   Updated: 2023/11/29 12:40:50 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				idx;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// Stack operations
void	ft_sa(t_stack **a);
void	ft_sb(t_stack **b);
void	ft_ss(t_stack **a, t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);
void	ft_pa(t_stack **a, t_stack **b);
void	ft_ra(t_stack **a);
void	ft_rb(t_stack **b);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_rra(t_stack **a);
void	ft_rrb(t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);

// Split functions
char	**ft_mod_split(char **str, int *argv, int *is_mal);

// Stack functions
t_stack	*ft_stnew(int value);
void	ft_push(t_stack **a, t_stack *new);
void	ft_init_stack(int value, t_stack **a, int to_free, char **argv);
void	ft_free_stack(t_stack **a);
void	ft_stack_idx(t_stack **s, int s_size);

// Check entry functions
void	ft_check_format(char *str, char **strs, int to_free, t_stack **a);
void	ft_error(int to_free, char **strs);
void	ft_check_double(int num, char **strs, int to_free);
void	ft_free_arg(char **argv);

// Quicksort 
void	ft_quicksort(t_stack **a, t_stack **b);

// Sort functions
void	ft_sort(t_stack **a, t_stack **b);
int		ft_slen(t_stack **s);
int		ft_is_sorted(t_stack **a);

// Sort additional functions
int		ft_rotate_needed(t_stack **s, int value);
int		ft_put_top(t_stack **s, int stack, int do_or_ret, int value);
void	ft_put_top_both(t_stack **a, t_stack **b, int value_a, int value_b);
int		ft_get_min(t_stack **s);
int		ft_get_max(t_stack **s);
int		ft_find_prev(t_stack **s, t_stack *elem);
int		ft_find_next(t_stack **s, t_stack *elem, int max);

// Sort for small numbers
void	ft_sort_exceptions(t_stack **a, int a_size);

#endif