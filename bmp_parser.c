/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:11:51 by thbernar          #+#    #+#             */
/*   Updated: 2018/10/29 21:10:04 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_color get_pixel_color(t_bmp *img, int x, int y)
{
	int os;
	t_color color;

	os = x + y * img->width;
	color.r = img->data[0 + os];
	color.g = img->data[1 + os];
	color.b = img->data[2 + os];
	return (color);
}

static void get_data_from_file(t_bmp *img, FILE *file)
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
	while ((c = getc(file)) != EOF && i < 22)
	{
		i++;
	}
	img->height = c;
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

void load_bmp(t_bmp *img, char *filename)
{
	FILE 	*file;

	file = fopen(filename, "r");
	if (file) {
		get_data_from_file(img, file);
		img->cursor.x = 0;
		img->cursor.y = 0;
		fclose(file);
	}
}
