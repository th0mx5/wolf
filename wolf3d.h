/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:17:32 by maxisimo          #+#    #+#             */
/*   Updated: 2018/09/11 12:40:04 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

typedef struct	s_var
{
	char	*file;
	char	*buf;
}			t_var;

int		execute(t_var *var, int fd);

int		ft_free(t_var *v, int t2);
int		error(t_var *v, int t1, int t2);

#endif
