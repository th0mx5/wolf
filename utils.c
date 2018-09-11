/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:38:08 by maxisimo          #+#    #+#             */
/*   Updated: 2018/09/11 13:05:15 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_free(t_var *v, int t2)
{
	if (t2 == 0)
		return (1);
	else if (t2 == 1)
		;
	free(v);
	return (1);
}

int		error(t_var *v, int t1, int t2)
{
	if (t1 == 0)
		write(2, "error : Dynamic memory allocation failed.", 41);
	else if (t1 == 1)
		write(2, "usage : ./wolf3d input_map", 26);
	/*
	 * Y'aura surement d'autres messages d'erreur a ajouter.
	*/
	write(2, "\n", 1);
	return (ft_free(v, t2));
}
