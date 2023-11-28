/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ab_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 14:37:06 by jgoudema          #+#    #+#             */
/*   Updated: 2023/11/17 14:37:22 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_sa(a);
	ft_sb(b);
}

void	ft_rr(t_stack **a, t_stack **b)
{
	if (*a == 0 || *b == 0)
		return ;
	*a = (*a)->next;
	*b = (*b)->next;
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	if (*b == 0 || *a == 0)
		return ;
	*b = (*b)->prev;
	*a = (*a)->prev;
}
