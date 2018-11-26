/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_app.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 18:43:12 by thbernar          #+#    #+#             */
/*   Updated: 2018/11/26 21:27:59 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_app_countmap(t_app *app)
{
	int		fd;
	int		count[3];
	char	*s;
	char	**array;

	count[2] = 0;
	count[0] = 0;
	if (((fd = open(app->fname, O_RDONLY)) < 0))
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
	free(s);
	app->map_size.x = count[2];
	app->map_size.y = count[0];
	ft_app_allocmap(app);
}

void		ft_app_allocmap(t_app *app)
{
	int i;

	i = 0;
	app->map = (int**)malloc(sizeof(int*) * app->map_size.x);
	if (app->map == NULL)
		exit(-1);
	while (i < app->map_size.x)
	{
		app->map[i] = (int*)malloc(sizeof(int) * app->map_size.y);
		if (app->map[i] == NULL)
			exit(-1);
		i++;
	}
	ft_app_writemap(app);
}

void		ft_app_writemap(t_app *app)
{
	int		fd;
	char	**array;
	char	*s;
	t_coord p;

	p.y = 0;
	if (((fd = open(app->fname, O_RDONLY)) < 0))
		ft_error("Fatal error : invalid file.");
	while ((get_next_line(fd, &s)) > 0 && p.y < app->map_size.y)
	{
		p.x = 0;
		array = ft_strsplit(s, ' ');
		free(s);
		while (p.x < app->map_size.x)
		{
			if (array[p.x])
				app->map[p.x][p.y] = ft_atoi(array[p.x]);
			else
				app->map[p.x][p.y] = 0;
			p.x++;
		}
		ft_free_strsplit(array);
		p.y++;
	}
	free(s);
}

static void	ft_app_calcplayerpos(t_app *app)
{
	t_coord p;

	p.y = 0;
	while (p.y < app->map_size.y)
	{
		p.x = 0;
		while (p.x < app->map_size.x)
		{
			if (app->map[p.x][p.y] == -1)
			{
				app->pos.y = (double)p.y + 0.5;
				app->pos.x = (double)p.x + 0.5;
				app->map[p.x][p.y] = 0;
				app->p_count++;
			}
			p.x++;
		}
		p.y++;
	}
}

void		ft_app_init(t_app *app)
{
	app->dir_x = -1;
	app->dir_y = 0;
	app->plane_x = 0;
	app->plane_y = 0.66;
	app->ms = 0.07;
	app->mv_up = 0;
	app->mv_down = 0;
	app->mv_right = 0;
	app->mv_left = 0;
	app->rt_right = 0;
	app->rt_left = 0;
	app->rt_up = 0;
	app->rt_dw = 0;
	app->p_count = 0;
	app->h = 0;
	app->t = 0;
	app->c = 0;
	app->weapon = 0;
	app->startscreen = 0;
	app->loop = 0;
	ft_app_countmap(app);
	ft_app_calcplayerpos(app);
	ft_import_textures(app);
}
