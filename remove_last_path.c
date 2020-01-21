/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_last_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 17:36:45 by plogan            #+#    #+#             */
/*   Updated: 2017/06/28 18:07:54 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void     remove_last_path(t_link *path)
{
	t_link  *new_last;

	new_last = path;
	if (!path)
		return ;
	while (new_last->next && new_last->next->next)
		new_last = new_last->next;
	free(new_last->next);
	new_last->next = NULL;
}
