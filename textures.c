/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 11:54:23 by thbernar          #+#    #+#             */
/*   Updated: 2018/12/10 12:49:29 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	textures_load(t_app *a)
{
	if (a->p_count <= 0)
		ft_error("Fatal error : invalid file.");
	bmp_loadfile(&a->textures[0], "textures/eagle2.bmp");
	bmp_loadfile(&a->textures[1], "textures/greystone.bmp");
	bmp_loadfile(&a->textures[2], "textures/redbrick.bmp");
	bmp_loadfile(&a->textures[3], "textures/wood.bmp");
	bmp_loadfile(&a->textures[4], "textures/glass.bmp");
	bmp_loadfile(&a->textures[5], "textures/mossy.bmp");
	bmp_loadfile(&a->textures[6], "textures/colorstone.bmp");
	bmp_loadfile(&a->textures[7], "textures/nebula.bmp");
	//bmp_loadfile(&a->textures[8], "textures/sky1.bmp");
	bmp_loadfile(&a->sprites[0], "sprites/ak47.bmp");
	bmp_loadfile(&a->sprites[1], "sprites/scope.bmp");
}
