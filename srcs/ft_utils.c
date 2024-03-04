/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:31:22 by mjochum           #+#    #+#             */
/*   Updated: 2023/08/20 18:58:15 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ptrswap(t_number **ptr1, t_number **ptr2)
{
	t_number	*swap;

	swap = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = swap;
}

void	ft_stackup(t_number **stack, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = NULL;
}

void	ft_stackdown(t_number **stack, int size)
{
	int	i;

	i = 0;
	while (size > 0)
	{
		stack[size] = stack[size - 1];
		size--;
	}
	stack[0] = NULL;
}
