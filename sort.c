/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:23:03 by jgoudema          #+#    #+#             */
/*   Updated: 2023/11/27 17:37:37 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_slen(t_stack **s)
{
	t_stack	*curr;
	int		len;

	len = 1;
	if (*s == 0)
		return (0);
	curr = (*s)->next;
	while (curr->value != (*s)->value)
	{
		curr = curr->next;
		len++;
	}
	return (len);
}

int	ft_is_sorted(t_stack **a)
{
	t_stack	*curr;

	if (!a)
		return (0);
	curr = (*a)->next;
	while ((*a)->value != curr->value)
	{
		if (curr->value < curr->prev->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	ft_sort(t_stack **a, t_stack **b)
{
	int	a_size;

	if (*a == 0 && *b == 0)
		return ;
	if (ft_is_sorted(a) == 1)
		return ;
	a_size = ft_slen(a);
	if (a_size <= 3)
		ft_sort_exceptions(a, a_size);
	if (ft_is_sorted(a) != 1 && ft_slen(a) > 3)
		ft_pb(a, b);
	if (ft_is_sorted(a) != 1 && ft_slen(a) > 3)
		ft_pb(a, b);
	ft_quicksort(a, b);
}
