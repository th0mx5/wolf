/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:04:48 by thbernar          #+#    #+#             */
/*   Updated: 2018/10/23 16:10:55 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_error(char *s)
{
	ft_putstr(s);
	exit(-1);
}

void	ft_pickcolors(t_app *map, int *color, int i)
{
	(void)map;
	(void)color;
	(void)i;
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

/*void	ft_app_printmap(t_app *app) // DEBUG
{
	t_coord p;

	p.y = 0;
	while (p.y < app->map_size.y)
	{
		p.x = 0;
		while (p.x < app->map_size.x)
		{
			ft_putnbr(app->map[p.x][p.y]);
			p.x++;
		}
		ft_putchar('\n');
		p.y++;
	}
}*/
