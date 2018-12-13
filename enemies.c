/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:54:23 by thbernar          #+#    #+#             */
/*   Updated: 2018/12/11 13:40:17 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void enemies_count(t_app *a)
{
	t_coord p;
	
	p.y = 0;
	a->enemies_count = 0;
	while (p.y < a->map_size.y)
	{
		p.x = 0;
		while (p.x < a->map_size.x)
		{
			if (a->map[p.x][p.y] == 10)
			{
				a->enemies_count++;
			}
			p.x++;
		}
		p.y++;
	}
}

static void enemies_alloc(t_app *a)
{
    a->enemies = malloc(sizeof(t_enemy) * a->enemies_count);
	if (!(a->enemies))
		exit(-1);
}

static void enemies_get_pos(t_app *a)
{
	t_coord p;
    int     i;
	
	p.y = 0;
    i = 0;
	while (p.y < a->map_size.y)
	{
		p.x = 0;
		while (p.x < a->map_size.x)
		{
			if (a->map[p.x][p.y] == 10)
			{
				a->enemies[i].pos.y = (double)p.y + 0.5;
				a->enemies[i].pos.x = (double)p.x + 0.5;
				a->enemies[i].sprite.img = &a->sprites[2];
				a->map[p.x][p.y] = 0;
                printf("-> %f %f\n", a->enemies[i].pos.x, a->enemies[i].pos.y);
                i++;
			}
			p.x++;
		}
		p.y++;
	}
    
}

void	enemies_init(t_app *a)
{
	enemies_count(a);
    enemies_alloc(a);
    enemies_get_pos(a);
    printf("enemies = %d\n", a->enemies_count);
}

void	enemies_draw(t_app *a)
{
	sprites_draw(a, a->enemies[0].sprite, a->enemies[0].pos);
	sprites_draw(a, a->enemies[1].sprite, a->enemies[1].pos);
	sprites_draw(a, a->enemies[2].sprite, a->enemies[2].pos);
}
