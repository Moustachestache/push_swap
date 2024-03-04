/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:05:54 by mjochum           #+#    #+#             */
/*   Updated: 2023/08/20 20:30:13 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static int	ft_validate_numlen(char *str)
{
	if (ft_strlen(str) > 10)
		return (0);
	return (1);
}

static int	ft_check_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) || !(str[i] == '-'))
			(void) i;
		else
			return (0);
		i++;
	}
	return (1);
}

static void	ft_check_duplicates(char **input, int size, t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < size)
	{
		while (i < size)
		{
			if ((ft_atoi(input[i]) == ft_atoi(input[j])) && (i != j))
				ft_exit(EXIT_FAILURE, vars);
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_validate_data(char **input, int size, t_vars *vars)
{
	char	*temp;
	int		i;

	i = 0;
	while (i < size)
	{
		if ((!ft_validate_numlen(input[i])) || (!ft_check_isnum(input[i])))
			ft_exit(EXIT_FAILURE, vars);
		temp = ft_itoa(ft_atoi(input[i]));
		if (ft_strncmp(input[i], temp, ft_strlen(input[i])))
		{
			free(temp);
			ft_exit(EXIT_FAILURE, vars);
		}
		free(temp);
		i++;
	}
	ft_check_duplicates(input, size, vars);
}
