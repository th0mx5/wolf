/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxisimo <maxisimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:30:12 by maxisimo          #+#    #+#             */
/*   Updated: 2018/09/11 12:58:32 by maxisimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
 * A mon avis le main est bien comme ca, la fonction error est dans utils et la fct execute est dans init
*/

int		main(int ac, char **av)
{
	t_var	*v;

	if (ac != 2)
		return (error(v, 1, 1));
	if (!(v = (t_var *)malloc(sizeof(t_var))))
		return (error(v, 0, 0));
	v->file = av[1];
	return (execute(v, 0));
}
