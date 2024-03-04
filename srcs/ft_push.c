/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:08:07 by mjochum           #+#    #+#             */
/*   Updated: 2023/08/16 16:30:42 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pa(t_vars *vars)
{
	if (vars->size2 == 0)
		return ;
	ft_stackdown(vars->stack1, vars->size1);
	vars->size1++;
	ft_ptrswap(&vars->stack2[0], &vars->stack1[0]);
	ft_stackup(vars->stack2, vars->size2);
	vars->size2--;
}

void	ft_pb(t_vars *vars)
{
	if (vars->size1 == 0)
		return ;
	ft_stackdown(vars->stack2, vars->size2);
	vars->size2++;
	ft_ptrswap(&vars->stack1[0], &vars->stack2[0]);
	ft_stackup(vars->stack1, vars->size1);
	vars->size1--;
}
