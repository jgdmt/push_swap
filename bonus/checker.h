/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:54:16 by jgoudema          #+#    #+#             */
/*   Updated: 2023/11/28 14:57:40 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
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

// Stack functions
t_stack	*ft_stnew(int value);
void	ft_push(t_stack **a, t_stack *new);
void	ft_init_stack(int value, t_stack **a);
void	ft_free_stack(t_stack **a);

// Check entry functions
void	ft_check_format(char *str, char **strs, int to_free, t_stack **a);
void	ft_error(int to_free, char **strs);
void	ft_check_double(int num, char **strs, int to_free);
int		ft_strcmp(char *s1, char *s2);
void	ft_free_arg(char **argv);

// Read entry functions
void	ft_read_op(t_stack **a);

// Sort functions
int		ft_slen(t_stack **s);
int		ft_is_sorted(t_stack **a);

// Get next line
char	*get_next_line(int fd);

// Split
char	**ft_mod_split(char **str, int *argv, int *is_mal);

#endif