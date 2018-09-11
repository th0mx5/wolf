/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 12:35:07 by maxisimo          #+#    #+#             */
/*   Updated: 2018/09/11 13:06:53 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		execute(t_var *v, int fd)
{
	if (!(v->buf = (char *)malloc(sizeof(char))))
		return (error(v, 0, 1));
	/*
	 * Faire un get next line pour lire le fichier
	 * Appeller les fonctions pour checker la map rentree en parametre qu'on codera dans un autre fichier (style ft_check.c)
	 * Appeler la(les) fonctions de conversion qu'on codera juste au dessus (penser aux valeur que l'on pourrait utiliser dans les calculs de raycasting, ceux de la map entree en parametres ne sont peut etre ps adaptes.
	 * Appeler la(les) fonction(s) d'initialisation qu'on codera juste au dessus
	*/
	return (0);
}
