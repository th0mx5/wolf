/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:54:23 by thbernar          #+#    #+#             */
/*   Updated: 2018/12/07 14:13:33 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void    sprites_load(t_app *a)
{
    bmp_loadfile(&a->sprites[2], "sprites/thomas.bmp");
    bmp_loadfile(&a->weapon.sprite, "sprites/ak47.bmp");
    a->sprites[2].p.x = 2.5;
    a->sprites[2].p.x = 2.5;
}

void    sprites_draw(t_app *a)
{
    //t_coord_d p1;
    //t_coord_d p2;
    //t_coord_d rel;
    //double  d;
    //double  c;
    //double  b;
    //p1 = a->sprites[2].p;
    //p2 = a->pos;
    //rel.x = p1.x - p2.x;
    //rel.y = p1.y - p2.y;
    //printf("%d %d, %d %d\n", a->sprites[2].p.x, a->sprites[2].p.y, a->pos.x, a->pos.y);
    //c = (p1.x - p2.x) * (p1.x - p2.x);
    //b = (p1.y - p2.y) * (p1.y - p2.y);
    //d = sqrt(c + b);
    //printf("%f, %f, %f\n", d, c, b);
    //a->sprites[2].scale = 5 - d / 2;
    double spriteX = a->sprites[2].p.x - a->pos.x;
    double spriteY = a->sprites[2].p.y - a->pos.y;
    double invDet = 1.0 / (a->plane_x * a->dir_y - a->dir_x * a->plane_y);
    double transformX = invDet * (a->dir_y * spriteX - a->dir_x * spriteY);
    double transformY = invDet * (-a->plane_y * spriteX + a->plane_x * spriteY);
    int spriteScreenX = (int)((WIN_W / 2) * (1 + transformX / transformY));
    if(transformY > 0)
        ft_put_bmp_to_img(a, a->sprites[2], spriteScreenX, WIN_H / 2);
}