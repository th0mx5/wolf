/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 13:43:25 by maxisimo          #+#    #+#             */
/*   Updated: 2018/10/10 16:13:50 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

static void	ft_find_player(t_var *v)
{
	int		x;
	int		y;
	int		count;

	x = 0;
	count = 0;
	while (x < v->map_size.x)
	{
		y = 0;
		while (y < v->map_size.y)
		{
			if (v->map[x][y] == 'X')
			{
				v->p_x = ((double)x + 0.5);
				v->p_y = ((double)y + 0.5);
				v->angle_ray = 0.0;
				count++;
			}
			y++;
		}
		x++;
	}
	if (count != 1)
		ft_error("Fatal error : invalid file.");
}

static void	ft_countmap(t_var *v)
{
	int		fd;
	int		count[3];
	char	*s;
	char	**array;

	count[2] = 0;
	count[0] = 0;
	if (((fd = open(v->fname, O_RDONLY)) < 0))
		ft_error("Fatal error : invalid file.");
	while ((get_next_line(fd, &s)) > 0)
	{
		array = ft_strsplit(s, ' ');
		free(s);
		count[1] = 0;
		while (array[count[1]])
			count[1]++;
		if (count[1] > count[2])
			count[2] = count[1];
		ft_free_strsplit(array);
		count[0]++;
	}
	v->map_size.x = count[2];
	v->map_size.y = count[0];
}

static void	ft_allocmap(t_var *v)
{
	int i;

	i = 0;
	v->map = (char**)malloc(sizeof(char*) * v->map_size.y);
	if (v->map == NULL)
		exit(-1);
	while (i < v->map_size.y)
	{
		v->map[i] = (char*)malloc(sizeof(char) * v->map_size.x);
		if (v->map[i] == NULL)
			exit(-1);
		i++;
	}
}

static void	ft_writemap(t_var *v)
{
	int		fd;
	int		i;
	int		j;
	char	**array;
	char	*s;

	i = 0;
	if (((fd = open(v->fname, O_RDONLY)) < 0))
		ft_error("Fatal error : invalid file.");
	while ((get_next_line(fd, &s)) > 0 && i < v->map_size.y)
	{
		j = 0;
		array = ft_strsplit(s, ' ');
		free(s);
		while (j < v->map_size.x)
		{
			if (array[j])
				v->map[i][j] = array[j][0];
			printf("%c ", v->map[i][j]);
			j++;
		}
		printf("\n");
		ft_free_strsplit(array);
		i++;
	}
}

void	start(t_var *v)
{
	ft_countmap(v);
	ft_allocmap(v);
	ft_writemap(v);
	ft_find_player(v);
}

/*
 * Du coup j'ai mis tout le reste en commentaires parce que je pense que mon
 * parsing est mieux mais si tu veux le reprendre ou quoi je l'ai laisse au
 * cas ou
*/

