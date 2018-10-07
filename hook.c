/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 09:44:58 by maxisimo          #+#    #+#             */
/*   Updated: 2018/10/07 16:36:38 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_keyhooked(int keycode, t_var *v)
{
	if (keycode == 53)
		exit(0);
/*	if (keycode == 123)
		v->pos.x = v->pos.x - 8;
	if (keycode == 124)
		v->pos.x = v->pos.x + 8;
	if (keycode == 125)
		v->pos.y = v->pos.y + 8;
	if (keycode == 126)
		v->pos.y = v->pos.y - 8;
	printf("pos : x = %d, y = %d\n", v->pos.x, v->pos.y);*/
	printf("keyhook%lf\n", v->p_x);
	raycasting(v);
	return (0);
}
