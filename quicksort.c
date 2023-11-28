/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:41:58 by jgoudema          #+#    #+#             */
/*   Updated: 2023/11/13 20:50:59 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_diff(int a_val, int b_val)
{
	if (a_val >= b_val)
		return (a_val);
	else
		return (b_val);
}

static int	ft_find_less(t_stack **a, t_stack **b, t_stack *elem)
{
	int	op_a;
	int	op_b;
	int	op;
	int	val;

	val = ft_find_prev(b, elem);
	op_a = ft_rotate_needed(a, elem->value);
	op_b = ft_rotate_needed(b, val);
	if (op_a <= ft_slen(a) - op_a && op_b <= ft_slen(b) - op_b)
		op = ft_diff(op_a, op_b);
	else if (op_a >= ft_slen(a) - op_a && op_b >= ft_slen(b) - op_b)
		op = ft_diff(ft_slen(a) - op_a, ft_slen(b) - op_b);
	else
	{
		if (op_a > ft_slen(a) - op_a)
			op_a = ft_slen(a) - op_a;
		if (op_b > ft_slen(b) - op_b)
			op_b = ft_slen(b) - op_b;
		op = op_a + op_b;
	}
	if (op < 0)
		op *= -1;
	return (op + 1);
}

static void	ft_push_back(t_stack **a, t_stack **b)
{
	int	prev;

	while (ft_slen(b) != 0)
	{
		prev = ft_find_next(a, *b, ft_slen(a) + ft_slen(b));
		ft_put_top(a, 1, 1, prev);
		ft_pa(a, b);
	}
	ft_put_top(a, 1, 1, ft_get_min(a));
}

void	ft_quicksort(t_stack **a, t_stack **b)
{
	t_stack	*val;
	t_stack	*curr;
	int		min_op;

	while (ft_slen(a) > 3)
	{
		val = *a;
		curr = (*a)->next;
		min_op = ft_find_less(a, b, val);
		while (curr->value != (*a)->value)
		{
			if (ft_find_less(a, b, curr) < min_op)
			{
				min_op = ft_find_less(a, b, curr);
				val = curr;
			}
			curr = curr->next;
		}
		ft_put_top_both(a, b, val->value, ft_find_prev(b, val));
		ft_pb(a, b);
	}
	ft_sort_exceptions(a, 3);
	ft_push_back(a, b);
}
