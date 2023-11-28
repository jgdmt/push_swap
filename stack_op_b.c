/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:41:58 by jgoudema          #+#    #+#             */
/*   Updated: 2023/11/13 19:11:25 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sb(t_stack **b)
{
	int	temp;
	int	idx_temp;

	if (*b == 0)
		return ;
	write(1, "sb\n", 3);
	temp = (*b)->value;
	idx_temp = (*b)->idx;
	(*b)->value = (*b)->next->value;
	(*b)->idx = (*b)->next->idx;
	(*b)->next->value = temp;
	(*b)->next->idx = idx_temp;
}

void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*a == 0)
		return ;
	write(1, "pb\n", 3);
	temp = (*a)->next;
	if (temp->value == (*a)->value)
		temp = 0;
	(*a)->next->prev = (*a)->prev;
	(*a)->prev->next = (*a)->next;
	(*a)->prev = *a;
	(*a)->next = *a;
	if (*b != 0)
	{
		(*a)->prev = (*b)->prev;
		(*b)->prev->next = *a;
		(*b)->prev = *a;
		(*a)->next = *b;
	}
	*b = *a;
	*a = temp;
}

void	ft_rb(t_stack **b)
{
	if (*b == 0)
		return ;
	write(1, "rb\n", 3);
	*b = (*b)->next;
}

void	ft_rrb(t_stack **b)
{
	if (*b == 0)
		return ;
	write(1, "rrb\n", 4);
	*b = (*b)->prev;
}
