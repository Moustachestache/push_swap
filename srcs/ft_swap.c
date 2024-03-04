/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:06:05 by mjochum           #+#    #+#             */
/*   Updated: 2023/08/16 16:27:33 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_vars *vars)
{
	if (vars->size1 < 2)
		return ;
	ft_ptrswap(&vars->stack1[0], &vars->stack1[1]);
}

void	ft_sb(t_vars *vars)
{
	if (vars->size2 < 2)
		return ;
	ft_ptrswap(&vars->stack2[0], &vars->stack2[1]);
}

void	ft_ss(t_vars *vars)
{
	ft_sa(vars);
	ft_sb(vars);
}
