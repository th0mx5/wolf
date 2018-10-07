/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 13:43:25 by maxisimo          #+#    #+#             */
/*   Updated: 2018/10/07 16:25:48 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
#include <stdio.h>

static int	ft_sizeline(char *str, int pos)
{
	int		i;

	i = 0;
	while (str[pos] != 0 && str[pos] != '\n')
	{
		pos++;
		i++;
	}
	return (i);
}

static int	convert(t_var *v, int lines)
{
	int		i;

	i = 0;
	v->y = -1;
	v->wth = ft_sizeline(v->buf, 0);
	v->pix = (int **)malloc(sizeof(int *) * 4);
	while (++i < 4)
		v->pix[i] = (int *)malloc(sizeof(int) * 2);
	i = 0;
	if (!(v->map = (int ***)malloc(sizeof(int **) * lines)))
	{
		free(v->buf);
		ft_error("error : Dynamic memory allocation failed.");
	}
	while (++v->y < lines && (v->x = 0) == 0)
	{
		if (!(v->map[v->y] = (int **)malloc(sizeof(int *) * v->wth)))
		{
			free(v->buf);
			free(v->map);
			ft_error("error : Dynamic memory allocation failed.");
		}
		v->map[v->y][v->x] = (int *)malloc(sizeof(int));
		v->map[v->y][v->x][0] = v->buf[i++];
	}
	free(v->buf);
	return (0);
}

static int	find_player(t_var *v, char c, int x, int y)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (v->buf[++i] != 0)
	{
		if (v->buf[i] == '\n' && ++y != 0)
			x = 0;
		else if (v->buf[i] == c && ++count != 0)
		{
			v->p_x = ((double)x - 0.5);
			v->p_y = ((double)y + 0.5);
			v->angle_ray = 0.;
		}
		x++;
	}
	return (count);
}

int			start(t_var *v)
{
	int		fd;
	int		lines;
	char	*s;

	fd = 0;
	lines = 0;
	if (!(v->buf = (char *)malloc(sizeof(char))))
		return (0);
	v->buf[0] = 0;
	if (((fd = open(v->fname, O_RDONLY)) < 0))
		ft_error("error : invalid file.");
	while (get_next_line(fd, &s) > 0 && ++lines > 0)
		v->buf = ft_strjoin(v->buf, ft_strjoin(s, "\n"));
	if (find_player(v, 'X', 0, 0) != 1 || convert(v, lines) != 0 || lines < 3)
	{
		free(v->buf);
		ft_error("error : invalid file.");
	}
	if (close(fd) == -1)
		free(v->map);
	return (0);
}

/*void	ft_countmap(t_var *v)
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
			{
				if (ft_strcmp(array[j], "X") == 0)
					v->map[i][j] = 2;
				else
					v->map[i][j] = ft_atoi(array[j]);
			}
			printf("%d ", v->map[i][j]);
			j++;
		}
		printf("\n");
		ft_free_strsplit(array);
		i++;
	}
}*/
