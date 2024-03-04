/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 12:10:55 by mjochum           #+#    #+#             */
/*   Updated: 2023/08/20 18:55:26 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_number	**ft_validate(t_vars *vars)
{
	t_number	**stack;
	static int	i = 0;

	stack = ft_calloc(vars->ac, sizeof(t_number *));
	if (!stack)
		ft_exit(EXIT_FAILURE, vars);
	while (vars->av[i] && i < vars->ac)
	{
		stack[i] = malloc(1 * sizeof(t_number));
		stack[i]->val = ft_atoi(vars->av[i]);
		stack[i]->pos = 0;
		i++;
	}
	return (stack);
}

static int	ft_count_arg(char *av)
{
	static int	i = 0;
	static int	j = 0;

	while (av[i])
	{
		while (av[i] && av[i] == ' ')
			i++;
		if (av[i])
			j++;
		while (av[i] && !(av[i] == ' '))
			i++;
	}
	return (j);
}

static t_vars	*ft_init(int ac, char **input)
{
	t_vars	*vars;

	vars = ft_calloc(1, sizeof(t_vars));
	vars->ac = ac;
	vars->size = ac;
	vars->av = input;
	ft_validate_data(input, ac, vars);
	vars->stack1 = ft_validate(vars);
	if (!vars->stack1)
		ft_exit(EXIT_FAILURE, vars);
	vars->stack2 = ft_calloc(vars->size, sizeof(t_number));
	vars->size1 = vars->size;
	vars->size2 = 0;
	if (!vars->stack2)
		ft_exit(EXIT_FAILURE, vars);
	return (vars);
}

char	**ft_copy_av(char **av, int size)
{
	static int	i = 0;
	char		**copy;

	copy = ft_calloc(size, sizeof(char *));
	while (i < size)
	{
		copy[i] = ft_strdup(av[i]);
		i++;
	}
	return (copy);
}

int	main(int ac, char *av[])
{
	t_vars	*vars;
	char	**input;

	if (ac == 1)
		return (ft_printf("Error. %s [\"numbers\"]", av[0]));
	else if (ac == 2)
	{
		input = ft_split(av[1], ' ');
		ac = ft_count_arg(av[1]);
		if (ac == 0)
			exit(EXIT_FAILURE);
	}
	else
	{
		ac--;
		input = ft_copy_av(av + 1, ac);
	}
	vars = ft_init(ac, input);
	ft_radix(vars);
	ft_exit(EXIT_SUCCESS, vars);
}
