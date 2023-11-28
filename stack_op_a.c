/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:41:25 by jgoudema          #+#    #+#             */
/*   Updated: 2023/11/13 19:10:57 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **a)
{
	int	temp;
	int	idx_temp;

	if (*a == 0)
		return ;
	write(1, "sa\n", 3);
	temp = (*a)->value;
	idx_temp = (*a)->idx;
	(*a)->value = (*a)->next->value;
	(*a)->idx = (*a)->next->idx;
	(*a)->next->value = temp;
	(*a)->next->idx = idx_temp;
}

void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*b == 0)
		return ;
	write(1, "pa\n", 3);
	temp = (*b)->next;
	if (temp->value == (*b)->value)
		temp = 0;
	(*b)->next->prev = (*b)->prev;
	(*b)->prev->next = (*b)->next;
	(*b)->prev = *b;
	(*b)->next = *b;
	if (*a != 0)
	{
		(*b)->prev = (*a)->prev;
		(*a)->prev->next = *b;
		(*a)->prev = *b;
		(*b)->next = *a;
	}
	*a = *b;
	*b = temp;
}

void	ft_ra(t_stack **a)
{
	if (*a == 0)
		return ;
	write(1, "ra\n", 3);
	*a = (*a)->next;
}

void	ft_rra(t_stack **a)
{
	if (*a == 0)
		return ;
	write(1, "rra\n", 4);
	*a = (*a)->prev;
}
