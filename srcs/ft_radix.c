/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 08:58:46 by mjochum           #+#    #+#             */
/*   Updated: 2023/08/20 19:38:18 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// 1. setup expected order
// 2. ??
static int	ft_checkorder(t_number **stack, t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->size - 1)
	{
		if (stack[i]->val > stack[i + 1]->val)
			return (0);
		i++;
	}
	return (1);
}

static void	*ft_nextnull(t_vars *vars)
{
	static int	i = 0;

	while (i < vars->size)
	{
		if (vars->stack1[i]->pos == 0)
			return (vars->stack1[i]);
		i++;
	}
	return (NULL);
}

static void	ft_presort(t_vars *vars)
{
	static int	i = 0;
	static int	j = 0;
	t_number	*next;

	while (i < vars->size)
	{
		next = ft_nextnull(vars);
		while (j < vars->size)
		{
			if (next->val > vars->stack1[j]->val && vars->stack1[j]->pos == 0)
				next = vars->stack1[j];
			j++;
		}
		j = 0;
		i++;
		next->pos = i; 
	}
}

static void	ft_getall(t_vars *vars)
{
	while (vars->size2 > 0)
	{
		ft_pa(vars);
		ft_printf("pa\n");
	}
}

void	ft_radix(t_vars *vars)
{
	static int	bit = 1;
	static int	i = 0;

	ft_presort(vars);
	while (!ft_checkorder(vars->stack1, vars))
	{
		while (i < vars->size)
		{
			if (!(vars->stack1[0]->pos & bit))
			{
				ft_pb(vars);
				ft_printf("pb\n");
			}
			else
			{
				ft_ra(vars);
				ft_printf("ra\n");
			}
			i++;
		}
		bit *= 2;
		ft_getall(vars);
		i = 0;
	}
}
