/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 15:04:48 by thbernar          #+#    #+#             */
/*   Updated: 2018/11/26 16:04:43 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_rgb_to_hex(t_color c)
{
	return (((c.r & 0xff) << 16) + ((c.g & 0xff) << 8) + (c.b & 0xff));
}

void	ft_put_pxl_to_img(t_app *a, t_color c, int x, int y)
{
	int hex_clr;

	hex_clr = ft_rgb_to_hex(c);
	ft_memcpy(a->img_data + 4 * WIN_W * y + x * 4, &hex_clr, sizeof(int));
}

void	ft_put_circle_to_img(t_app *a, t_circle *c)
{
	put_pxl_to_img(a, c->xc + c->x, c->yc - c->y, 0xFF0000);
	put_pxl_to_img(a, c->xc - c->x, c->yc - c->y, 0xFF0000);
	put_pxl_to_img(a, c->xc + c->x, c->yc + c->y, 0xFF0000);
	put_pxl_to_img(a, c->xc - c->x, c->yc + c->y, 0xFF0000);
	put_pxl_to_img(a, c->xc + c->y, c->yc - c->x, 0xFF0000);
	put_pxl_to_img(a, c->xc - c->y, c->yc - c->x, 0xFF0000);
	put_pxl_to_img(a, c->xc + c->y, c->yc + c->x, 0xFF0000);
	put_pxl_to_img(a, c->xc - c->y, c->yc + c->x, 0xFF0000);
	if (c->d > 0)
	{
		c->y--;
		c->d -= 8 * c->y;
	}
	c->x++;
	c->d = c->d + 8 * c->x + 4;
}

void	ft_import_textures(t_app *a)
{
	if (a->p_count != 1)
		ft_error("Fatal error : invalid map.");
	bmp_loadfile(&a->textures[0], "textures/earth.bmp");
	bmp_loadfile(&a->textures[1], "textures/greystone.bmp");
	bmp_loadfile(&a->textures[2], "textures/redbrick.bmp");
	bmp_loadfile(&a->textures[3], "textures/wood.bmp");
	bmp_loadfile(&a->textures[4], "textures/glass.bmp");
	bmp_loadfile(&a->textures[5], "textures/mossy.bmp");
	bmp_loadfile(&a->textures[6], "textures/colorstone.bmp");
	bmp_loadfile(&a->textures[7], "textures/nebula.bmp");
	bmp_loadfile(&a->textures[8], "textures/sky1.bmp");
	bmp_loadfile(&a->sprites[0], "sprites/ak47.bmp");
}

void	ft_put_bmp_to_img(t_app *a, t_bmp bmp, int x, int y)
{
	t_coord p;
	t_color	c;
	t_coord tmp;

	p.x = 0;
	p.y = 0;
	while (p.y < bmp.height * bmp.scale)
	{
		p.x = 0;
		while (p.x < bmp.width * bmp.scale)
		{
			c = get_pixel_color(&bmp, p.x / bmp.scale, p.y / bmp.scale);
			tmp.x = x + p.x;
			tmp.y = y - p.y + bmp.height * bmp.scale;
			if (ft_rgb_to_hex(c) != 0xB80087 && tmp.x > 0 && tmp.y < WIN_W)
				ft_put_pxl_to_img(a, c, tmp.x, tmp.y);
			p.x++;
		}
		p.y++;
	}
}
