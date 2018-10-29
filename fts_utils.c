/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:04:48 by thbernar          #+#    #+#             */
/*   Updated: 2018/10/29 19:29:53 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_printcontrols(void)
{
	ft_putstr("--- Controls ---\n");
	ft_putstr("+ : zoom in\n");
	ft_putstr("- : zoom out\n");
	ft_putstr("ARROWS : move\n");
	ft_putstr("MOUSE (julia only) : toggle C\n");
	ft_putstr("LEFT OPTION : increase I\n");
	ft_putstr("LEFT CMD : decrease I\n");
	ft_putstr("LEFT CTRL : toggle colors\n");
	ft_putstr("--- End Controls ---\n");
}

void	ft_error(char *s)
{
	ft_putstr(s);
	exit(-1);
}

int		ft_rgb_to_hex(t_color c)
{
	return (((c.r & 0xff) << 16) + ((c.g & 0xff) << 8) + (c.b & 0xff));
}

double	ft_abs_d(double nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}

int		ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	else
		return (nb);
}
void	ft_free_strsplit(char **array)
{
	int i;

	i = 0;
	while (array	[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
