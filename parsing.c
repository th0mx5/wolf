/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 13:43:25 by maxisimo          #+#    #+#             */
/*   Updated: 2018/10/02 14:07:36 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_init(t_var *v)
{
	ft_countmap(v);
	ft_allocmap(v);
	ft_writemap(v);
}

void	ft_countmap(t_var *v)
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

void	ft_allocmap(t_var *v)
{
	int i;

	i = 0;
	v->map = (int**)malloc(sizeof(int*) * v->map_size.y);
	if (v->map == NULL)
		exit(-1);
	while (i < v->map_size.y)
	{
		v->map[i] = (int*)malloc(sizeof(int) * v->map_size.x);
		if (v->map[i] == NULL)
			exit(-1);
		i++;
	}
}

void	ft_writemap(t_var *v)
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
<<<<<<< HEAD:parsing.c
			{
				if (ft_strcmp(array[j], "X") == 0)
					v->map[i][j] = 2;
				else
					v->map[i][j] = ft_atoi(array[j]);
			}
			/*else
				v->map[i][j] = 0;*/
			//printf("%c", array[i][j]);
			printf("%d ", v->map[i][j]);
=======
				(app->map[i][j] = ft_atoi(array[j]) == 1) ? 64 : 0;
			else
				app->map[i][j] = 0;
			printf("%d ", app->map[i][j]);
>>>>>>> 253b7909840405ef38ddb8066f2e111e73db4470:fts_app.c
			j++;
		}
		printf("\n");
		ft_free_strsplit(array);
		i++;
	}
}
