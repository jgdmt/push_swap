/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:36:04 by jgoudema          #+#    #+#             */
/*   Updated: 2023/11/28 14:58:27 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sa(t_stack **a)
{
	int	temp;

	if (*a == 0)
		return ;
	temp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = temp;
}

void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*b == 0)
		return ;
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
	*a = (*a)->next;
}

void	ft_rra(t_stack **a)
{
	if (*a == 0)
		return ;
	*a = (*a)->prev;
}
