/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:04:48 by thbernar          #+#    #+#             */
/*   Updated: 2018/11/18 18:07:47 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_rgb_to_hex(t_color c)
{
	return (((c.r & 0xff) << 16) + ((c.g & 0xff) << 8) + (c.b & 0xff));
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

void	ft_put_pxl_to_img(t_app *a, t_color c, int x, int y)
{
	int hex_clr;

	hex_clr = ft_rgb_to_hex(c);
	ft_memcpy(a->img_data + 4 * WIN_W * y + x * 4, &hex_clr, sizeof(int));
}

void	ft_import_textures(t_app *a)
{
	load_bmp(&a->textures[0], "textures/texture_wall1.bmp");
	load_bmp(&a->textures[1], "textures/wall2.bmp");
	load_bmp(&a->textures[2], "textures/earth.bmp");
	load_bmp(&a->textures[3], "textures/red.bmp");
	load_bmp(&a->textures[4], "textures/metal1.bmp");
	load_bmp(&a->textures[5], "textures/metal2.bmp");
	load_bmp(&a->textures[6], "textures/bois1.bmp");
	load_bmp(&a->textures[7], "textures/nebula.bmp");
	load_bmp(&a->textures[8], "textures/death.bmp");
}

void	ft_put_bmp_to_img(t_app *a, t_bmp bmp, int x, int y)
{
	t_coord p;
	t_color	c;

	p.x = 0;
	p.y = 0;
	while (p.y < bmp.height * bmp.scale)
	{
		p.x = 0;
		while (p.x < bmp.width * bmp.scale)
		{
			c = get_pixel_color(&bmp, p.x / bmp.scale, p.y / bmp.scale);
			ft_put_pxl_to_img(a, c, x + p.x, y + p.y);
			p.x++;
		}
		p.y++;
	}
}
