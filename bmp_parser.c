/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:11:51 by thbernar          #+#    #+#             */
/*   Updated: 2018/11/13 13:42:35 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_color		get_pixel_color(t_bmp *img, int x, int y)
{
	int		os;
	t_color	color;

	os = (x + y * img->width) * 3;
	color.r = img->data[0 + os];
	color.g = img->data[1 + os];
	color.b = img->data[2 + os];
	return (color);
}

static void	get_data_from_file2(t_bmp *img, FILE *file, int c, int i)
{
	img->height = c;
	i++;
	img->height += getc(file) << 8;
	i++;
	img->height += getc(file) << 16;
	i++;
	img->height += getc(file) << 24;
	i++;
	while ((c = getc(file)) != EOF && i < img->data_offset - 1)
	{
		i++;
	}
	img->data = (int*)malloc(sizeof(int) * img->width * img->height * 3);
	i = 0;
	while ((c = getc(file)) != EOF)
	{
		if (i % 3 == 0)
			img->data[i + 2] = c;
		if (i % 3 == 1)
			img->data[i] = c;
		if (i % 3 == 2)
			img->data[i - 2] = c;
		i++;
	}
}

static void	get_data_from_file(t_bmp *img, FILE *file)
{
	int c;
	int i;

	i = 0;
	while ((c = getc(file)) != EOF && i < 10)
	{
		i++;
	}
	img->data_offset = c;
	i++;
	while ((c = getc(file)) != EOF && i < 18)
	{
		i++;
	}
	img->width = c;
	i++;
	img->width += getc(file) << 8;
	i++;
	img->width += getc(file) << 16;
	i++;
	img->width += getc(file) << 24;
	i++;
	while ((c = getc(file)) != EOF && i < 22)
	{
		i++;
	}
	get_data_from_file2(img, file, c, i);
}

void		load_bmp(t_bmp *img, char *filename)
{
	FILE	*file;

	file = fopen(filename, "r");
	if (file)
	{
		get_data_from_file(img, file);
		img->scale = 1;
		fclose(file);
	}
	printf("w = %d\n", img->width);
	printf("h = %d\n", img->height);
}
