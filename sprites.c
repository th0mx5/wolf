/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:54:23 by thbernar          #+#    #+#             */
/*   Updated: 2018/12/05 17:14:42 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void    sprites_load(t_app *a)
{
    bmp_loadfile(&a->sprites[2], "sprites/thomas.bmp");
    bmp_loadfile(&a->weapon.fired, "sprites/ak47.bmp");
    bmp_loadfile(&a->weapon.normal, "sprites/ak47fired.bmp");
    a->sprites[2].p.x = 2.5;
    a->sprites[2].p.x = 2.5;
}

void    sprites_draw(t_app *a)
{
    // Draw all sprites
    t_coord_d p1;
    t_coord_d p2;
    t_coord_d rel;
    double  d;
    double  c;
    double  b;

    p1 = a->sprites[2].p;
    p2 = a->pos;
    rel.x = p1.x - p2.x;
    rel.y = p1.y - p2.y;
    double invDet = 1.0 / (a->plane_x * a->dir_y - a->dir_x * a->plane_y);
    double transformX = invDet * (a->dir_y * rel.x - a->dir_x * rel.y);
    double transformY = invDet * (-a->plane_y * rel.x + a->plane_x * rel.y);
    int spriteScreenX = (int)((WIN_W / 2) * (1 + transformX / transformY));
    int spriteHeight = abs((int)(WIN_H / (transformY)));
    int drawStartY = -spriteHeight / 2 + WIN_H / 2;
    if(drawStartY < 0) drawStartY = 0;
    int drawEndY = spriteHeight / 2 + WIN_H / 2;
    if(drawEndY >= WIN_H) drawEndY = WIN_H - 1;
    int spriteWidth = abs((int)(WIN_H / (transformY)));
    int drawStartX = -spriteWidth / 2 + spriteScreenX;
    if(drawStartX < 0) drawStartX = 0;
    int drawEndX = spriteWidth / 2 + spriteScreenX;
    if(drawEndX >= WIN_W) drawEndX = WIN_W - 1;
    //printf("%d %d, %d %d\n", a->sprites[2].p.x, a->sprites[2].p.y, a->pos.x, a->pos.y);
    c = (p1.x - p2.x) * (p1.x - p2.x);
    b = (p1.y - p2.y) * (p1.y - p2.y);
    d = sqrt(c + b);
    //printf("%f, %f, %f\n", d, c, b);
    ft_put_bmp_to_img(a, a->sprites[2], WIN_W / 2 * (1 + transformX / transformY), WIN_H / 2);
    /*a->sprites[2].scale = 5 - d / 2;
    for(int stripe = drawStartX; stripe < drawEndX; stripe++)
    {
      int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * a->sprites[2].width / spriteWidth) / 256;
      if(transformY > 0 && stripe > 0 && stripe < WIN_W)
      for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
      {
        int d = (y) * 256 - WIN_H * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
        int texY = ((d * a->sprites[2].height) / spriteHeight) / 256;
        t_color color = get_pixel_color(&a->sprites[2], texX, texY);
        int clr = ft_rgb_to_hex(color);
        ft_memcpy(a->img_data + 4 * WIN_W * y + stripe * 4,
				&clr, sizeof(int));
      }
    }*/
}