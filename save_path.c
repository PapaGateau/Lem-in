/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:22:05 by plogan            #+#    #+#             */
/*   Updated: 2017/06/28 18:45:50 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
//necessary?
void			add_path(t_link **path, t_room *room);

static t_path	*create_new_paths(t_link *path)
{
	t_path	*new;

	if (!(new = (t_path *)malloc(sizeof(t_path))))
		return (new);
	new->path = path;
	new->weight = 0;
	new->temp_weight = 0;
	new->traffic = 0;
	new->next = NULL;
	return (new);
}

void			save_path(t_path **paths, t_link *path)
{
	t_link	*path_copy;
	t_path	*new;
	t_link	*p;
	t_path	*ps;

	p = path;
	ps = *paths;
	path_copy = NULL;
	new = NULL;
	while (p)
	{
		add_path(&path_copy, p->room);
		p = p->next;
	}
	new = create_new_paths(path_copy);
	if (!(*paths))
	{
		*paths = new;
		return ;
	}
	while (ps->next)
		ps = ps->next;
	ps->next = new;
}
