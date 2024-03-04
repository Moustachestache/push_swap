/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:10:04 by mjochum           #+#    #+#             */
/*   Updated: 2023/08/20 18:48:51 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "srcs/lib/libft.h"

typedef struct s_number {
	int				pos;
	long long int	val;
}			t_number;

typedef struct s_vars {
	int			ac;
	int			size;
	int			size1;
	int			size2;
	t_number	**stack1;
	t_number	**stack2;
	char		**av;
}			t_vars;

void	ft_validate_data(char **input, int size, t_vars *vars);
void	ft_radix(t_vars *vars);
void	ft_exit(int err, t_vars *vars);
void	ft_ptrswap(t_number **ptr1, t_number **ptr2);
void	ft_stackdown(t_number **stack, int size);
void	ft_stackup(t_number **stack, int size);
void	ft_sa(t_vars *vars);
void	ft_sb(t_vars *vars);
void	ft_ss(t_vars *vars);
void	ft_pa(t_vars *vars);
void	ft_pb(t_vars *vars);
void	ft_ra(t_vars *vars);
void	ft_rb(t_vars *vars);
void	ft_rr(t_vars *vars);
void	ft_rra(t_vars *vars);
void	ft_rrb(t_vars *vars);
void	ft_rrr(t_vars *vars);

#endif
