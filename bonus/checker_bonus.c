/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoudema <jgoudema@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 13:58:37 by jgoudema          #+#    #+#             */
/*   Updated: 2023/11/29 12:42:09 by jgoudema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_free_arg(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

static long int	ft_atoli(char *str, t_stack **a, int to_free, char **argv)
{
	long int	num;
	int			sign;
	int			i;

	num = 0;
	sign = 1;
	i = -1;
	if (str[++i] == '-')
		sign = -1;
	if (str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		num = (num * 10) + (str[i++] - 48);
	num = num * sign;
	if (num < -2147483648 || num > 2147483647)
	{
		ft_free_stack(a);
		ft_error(to_free, argv);
	}
	return (num);
}

int	main(int argc, char *argv[])
{
	t_stack		*a;
	long int	num;
	int			is_mal;

	a = 0;
	if (argc < 2)
		return (0);
	is_mal = 0;
	if (argc == 2)
		argv = ft_mod_split(argv, &argc, &is_mal);
	ft_check_double(argc, argv, is_mal);
	while (--argc >= 1)
	{
		ft_check_format(argv[argc], argv, is_mal, &a);
		num = ft_atoli(argv[argc], &a, is_mal, argv);
		ft_init_stack(num, &a, is_mal, argv);
	}
	if (is_mal == 1)
		ft_free_arg(argv);
	ft_read_op(&a);
	ft_free_stack(&a);
	return (0);
}
