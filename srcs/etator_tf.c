/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etator_tf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:14:02 by mjochum           #+#    #+#             */
/*   Updated: 2023/08/20 19:36:00 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra(t_vars *vars)
{
	t_number	*swap;

	swap = NULL;
	ft_ptrswap(&swap, &vars->stack1[vars->size1 - 1]);
	ft_stackdown(vars->stack1, vars->size1);
	vars->stack1[0] = swap;
}

void	ft_rrb(t_vars *vars)
{
	t_number	*swap;

	swap = NULL;
	ft_ptrswap(&swap, &vars->stack2[vars->size2 - 1]);
	ft_stackdown(vars->stack2, vars->size2);
	vars->stack2[0] = swap;
}

void	ft_rrr(t_vars *vars)
{
	ft_rra(vars);
	ft_rrb(vars);
}
