/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjochum <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 10:55:03 by mjochum           #+#    #+#             */
/*   Updated: 2023/08/08 17:44:50 by mjochum          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_info {
	int		readsize;
	char	*leftovers;
}		t_info;

char	*get_next_line(int fd);
char	*ft_panic(char *str, t_info info, int panic_type);

void	*ft_buildline(char *str, t_info info, int fd);
void	*ft_stradd(char *str, t_info info);
void	*ft_trimshit(char *str, t_info info);

int		ft_hasret(char *s);

#endif
