/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op_ab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:41:37 by jgoudema          #+#    #+#             */
/*   Updated: 2023/11/13 19:11:10 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_sa(a);
	ft_sb(b);
}

void	ft_rr(t_stack **a, t_stack **b)
{
	if (*a == 0 || *b == 0)
		return ;
	write(1, "rr\n", 3);
	*a = (*a)->next;
	*b = (*b)->next;
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	if (*b == 0 || *a == 0)
		return ;
	write(1, "rrr\n", 4);
	*b = (*b)->prev;
	*a = (*a)->prev;
}
