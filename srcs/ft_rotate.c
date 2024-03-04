/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:10:04 by mjochum           #+#    #+#             */
/*   Updated: 2023/08/16 16:36:08 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_vars *vars)
{
	t_number	*swap;

	swap = NULL;
	ft_ptrswap(&vars->stack1[0], &swap);
	ft_stackup(vars->stack1, vars->size1);
	vars->stack1[vars->size1 - 1] = swap;
}

void	ft_rb(t_vars *vars)
{
	t_number	*swap;

	swap = NULL;
	ft_ptrswap(&vars->stack2[0], &swap);
	ft_stackup(vars->stack2, vars->size2);
	vars->stack1[vars->size2 - 1] = swap;
}

void	ft_rr(t_vars *vars)
{
	ft_ra(vars);
	ft_rb(vars);
}
