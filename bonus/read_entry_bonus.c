/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_entry_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:50:27 by jgoudema          #+#    #+#             */
/*   Updated: 2023/11/27 17:51:14 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_do_op(char *str, t_stack **a, t_stack **b)
{
	if (ft_strcmp(str, "sa") == 0)
		ft_sa(a);
	else if (ft_strcmp(str, "sb") == 0)
		ft_sb(b);
	else if (ft_strcmp(str, "pa") == 0)
		ft_pa(a, b);
	else if (ft_strcmp(str, "pb") == 0)
		ft_pb(a, b);
	else if (ft_strcmp(str, "ra") == 0)
		ft_ra(a);
	else if (ft_strcmp(str, "rb") == 0)
		ft_rb(b);
	else if (ft_strcmp(str, "rra") == 0)
		ft_rra(a);
	else if (ft_strcmp(str, "rrb") == 0)
		ft_rrb(b);
	else if (ft_strcmp(str, "rr") == 0)
		ft_rr(a, b);
	else if (ft_strcmp(str, "rrr") == 0)
		ft_rrr(a, b);
	else
		return (-1);
	return (0);
}

static void	ft_put_back(t_stack **a, t_stack **b)
{
	while (ft_slen(b) != 0)
		ft_pa(a, b);
}

void	ft_read_op(t_stack **a)
{
	char	*str;
	t_stack	*b;
	int		error;

	str = "";
	b = 0;
	error = 0;
	while (str)
	{
		str = get_next_line(0);
		if (str && ft_do_op(str, a, &b) == -1)
			error = 1;
		free(str);
	}
	if (error == 1)
	{
		ft_put_back(a, &b);
		ft_free_stack(a);
		ft_error();
	}
	if (ft_slen(&b) != 0 || ft_is_sorted(a) != 1)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	ft_put_back(a, &b);
}
