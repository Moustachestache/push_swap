/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:24:13 by mjochum           #+#    #+#             */
/*   Updated: 2023/08/20 19:07:28 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_stack(t_number **stack, int size, t_vars *vars)
{
	int	i;

	(void) vars;
	i = 0;
	while (i < size)
	{
		if (stack[i])
			free(stack[i]);
		i++;
	}
}

void	ft_free_av(char **av, int size, t_vars *vars)
{
	(void) vars;
	while (size > 0)
	{
		size--;
		if (av[size])
			free(av[size]);
	}
}

void	ft_exit(int err, t_vars *vars)
{
	if (err == EXIT_FAILURE)
		ft_printf("Error.");
	if (vars)
	{
		if (vars->av)
		{
			ft_free_av(vars->av, vars->ac, vars);
			free(vars->av);
		}
		if (vars->stack1)
		{
			ft_free_stack(vars->stack1, vars->size1, vars);
			free(vars->stack1);
		}
		if (vars->stack2)
		{
			ft_free_stack(vars->stack2, vars->size2, vars);
			free(vars->stack2);
		}
		free(vars);
	}
	exit(err);
}
