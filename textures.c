/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:54:23 by thbernar          #+#    #+#             */
/*   Updated: 2018/12/11 13:23:25 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	textures_load(t_app *a)
{
	if (a->p_count <= 0)
		ft_error("Fatal error : invalid file.");
	bmp_loadfile(&a->textures[0], "textures/bigdoor.bmp");
	bmp_loadfile(&a->textures[1], "textures/dude.bmp");
	bmp_loadfile(&a->textures[2], "textures/metal.bmp");
	bmp_loadfile(&a->textures[3], "textures/floor.bmp");
	bmp_loadfile(&a->textures[4], "textures/skulwall.bmp");
	bmp_loadfile(&a->textures[5], "textures/marbface.bmp");
	bmp_loadfile(&a->textures[6], "textures/skulwall2.bmp");
	//bmp_loadfile(&a->textures[8], "textures/sky1.bmp");
}
