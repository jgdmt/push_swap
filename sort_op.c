/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:15:04 by jgoudema          #+#    #+#             */
/*   Updated: 2023/11/13 19:12:35 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate_needed(t_stack **s, int value)
{
	int		len;
	t_stack	*temp;

	len = 0;
	temp = *s;
	while (temp->value != value)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}

static void	ft_put_top_do(t_stack **s, void (rev)(t_stack **s), int op)
{
	while (op > 0)
	{
		rev(s);
		op--;
	}
}

int	ft_put_top(t_stack **s, int stack, int do_or_ret, int value)
{
	int	op;
	int	rev;

	op = ft_rotate_needed(s, value);
	rev = 0;
	if (op > ft_slen(s) - op)
	{
		op = ft_slen(s) - op;
		rev = 1;
	}
	if (stack == 1 && do_or_ret == 1)
	{
		if (rev == 0)
			ft_put_top_do(s, ft_ra, op);
		else
			ft_put_top_do(s, ft_rra, op);
	}
	else if (stack == 2 && do_or_ret == 1)
	{
		if (rev == 0)
			ft_put_top_do(s, ft_rb, op);
		else
			ft_put_top_do(s, ft_rrb, op);
	}
	return (op);
}

static void	ft_put_top_do_both(t_stack **a, t_stack **b, 
			void (rev)(t_stack **a, t_stack **b), int *rrr_ab)
{
	while (rrr_ab[0] > 0 && rrr_ab[1] > 0)
	{
		rev(a, b);
		rrr_ab[0] -= 1;
		rrr_ab[1] -= 1;
	}
}

void	ft_put_top_both(t_stack **a, t_stack **b, int value_a, int value_b)
{
	int	r_ab[2];
	int	rr_ab[2];

	r_ab[0] = ft_rotate_needed(a, value_a);
	rr_ab[0] = ft_slen(a) - r_ab[0];
	r_ab[1] = ft_rotate_needed(b, value_b);
	rr_ab[1] = ft_slen(b) - r_ab[1];
	if (r_ab[0] <= rr_ab[0] && r_ab[1] <= rr_ab[1])
		ft_put_top_do_both(a, b, ft_rr, r_ab);
	else if (r_ab[0] >= rr_ab[0] && r_ab[1] >= rr_ab[1])
		ft_put_top_do_both(a, b, ft_rrr, rr_ab);
	ft_put_top(a, 1, 1, value_a);
	ft_put_top(b, 2, 1, value_b);
}
