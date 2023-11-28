/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_exceptions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:09:15 by jgoudema          #+#    #+#             */
/*   Updated: 2023/11/13 19:11:38 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_three(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->prev->value;
	if ((first > second && second > third) || (second > third && third > first) 
		|| (third > first && first > second))
		ft_sa(a);
	if ((first > second && second > third) || (second > first && first > third))
		ft_rra(a);
	if ((second > third && third > first) || (first > third && third > second))
		ft_ra(a);
}

void	ft_sort_exceptions(t_stack **a, int a_size)
{
	if (a_size == 2)
		ft_sa(a);
	else if (a_size == 3)
		ft_sort_three(a);
}
