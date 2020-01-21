/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 14:56:39 by plogan            #+#    #+#             */
/*   Updated: 2017/06/28 14:58:19 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static t_link   *get_last_path(t_link *path)
{
	t_link  *temp;

	temp = path;
	if (!temp)
		return (NULL);
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void        add_path(t_link **path, t_room *room)
{
	t_link  *new_path;
	t_link  *last_path;

	if (!(new_path = (t_link *)malloc(sizeof(t_link))))
		return ;
	new_path->room = room;
	new_path->next = NULL;
	if (!(*path))
		*path = new_path;
	else
	{
		last_path = get_last_path(*path);
		last_path->next = new_path;
	}
}
