/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thbernar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 15:11:51 by thbernar          #+#    #+#             */
/*   Updated: 2018/10/26 16:49:24 by thbernar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_bmp
{
	int		width;
	int		height;
	int		data_offset;
	int		*data;
}		t_bmp;

static void get_pixel_color(t_bmp *img, int x, int y)
{
	int os;

	os = x + y * img->width;
	printf("(%d, %d, %d)", img->data[0 + os], img->data[1 + os], img->data[2 + os]);
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

static void load_bmp(t_bmp *img, char *filename)
{
	FILE 	*file;

	file = fopen(filename, "r");
	if (file) {
		get_data_from_file(img, file);
		fclose(file);
	}
}

int main(int ac, char **av)
{
	t_bmp texture;
	load_bmp(&texture, av[1]);
	get_pixel_color(&texture, 0, 0);
	printf("-------------\n");
	printf("width = %d\n", texture.width);
	printf("height = %d\n", texture.height);
	printf("data_offset = %d\n", texture.data_offset);
	return (0);
}
