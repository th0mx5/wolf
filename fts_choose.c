/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_choose.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:45:32 by maxisimo          #+#    #+#             */
/*   Updated: 2018/12/10 17:34:53 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_color	ft_choose_tex(t_app *a)
{
	if (a->side == 0 && a->raydir_x < 0)
		a->texnum = 5;
	if (a->side == 0 && a->raydir_x > 0)
		a->texnum = 1;
	if (a->side == 1 && a->raydir_y < 0)
		a->texnum = 0;
	if (a->side == 1 && a->raydir_y > 0)
		a->texnum = 2;
	return (get_pixel_color(&a->textures[a->texnum], a->texx, a->texy));
}

void	ft_choose_color(int x, int start, t_app *a)
{
	t_color c1;

	c1 = ft_choose_tex(a);
	ft_apply_shadow_to_color(&c1, a->clr_intensity);
	ft_put_pxl_to_img(a, c1, x, start);
}
