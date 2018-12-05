/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:54:23 by thbernar          #+#    #+#             */
/*   Updated: 2018/11/26 23:04:23 by maxisimo         ###   ########.fr       */
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
    // Draw all sprites
    t_coord_d p1;
    t_coord_d p2;
    t_coord_d rel;
    double  d;
    double  c;
    double  b;
    (void)a;
    p1 = a->sprites[2].p;
    p2 = a->pos;
    rel.x = p1.x - p2.x;
    rel.y = p1.y - p2.y;
    double invDet = 1.0 / (a->plane_x * a->dir_y - a->dir_x * a->plane_y);
    double transformX = invDet * (a->dir_y * rel.x - a->dir_x * rel.y);
    double transformY = invDet * (-a->plane_y * rel.x + a->plane_x * rel.y);
    //printf("%d %d, %d %d\n", a->sprites[2].p.x, a->sprites[2].p.y, a->pos.x, a->pos.y);
    c = (p1.x - p2.x) * (p1.x - p2.x);
    b = (p1.y - p2.y) * (p1.y - p2.y);
    d = sqrt(c + b);
    //printf("%f, %f, %f\n", d, c, b);
    //a->sprites[2].scale = 5 - d / 2;
    ft_put_bmp_to_img(a, a->sprites[2], WIN_W / 2 * (1 + transformX / transformY), WIN_H / 2);
}