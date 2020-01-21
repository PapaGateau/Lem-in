/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 15:44:42 by plogan            #+#    #+#             */
/*   Updated: 2017/06/28 17:46:36 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int				is_loop(t_link *path, int index)
{
	t_link	*temp;

	temp = path;
	if (!temp)
		return (0);
	if (!path->next)
		return (0);
	while (temp->next->next)
	{
		if (temp->room->index == index)
			return (1);
		temp = temp->next;
	}
	return (0);
}

static void		find_paths(t_room *room, t_link *path)
{
	t_link	*links;

	if (!room || is_loop(path, room->index))
	{
		remove_last_path(path);
		return ;
	}
	else if (room->type == 1)
	{
		save_path(&ft_s()->paths, path); // added first param
		remove_last_path(path);
		return ;
	}
	links = room->links;
	while (links)
	{
		add_path(&path, links->room);
		find_paths(links->room, path);
		links = links->next;
	}
	remove_last_path(path);
}

static void		assign_weight(void)
{
	t_path	*temp;
	t_link	*links;

	temp = ft_s()->paths;
	while (temp)
	{
		links = temp->path;
		while (links->next)
		{
			temp->weight++;
			links = links->next;
		}
		temp = temp->next;
	}
}

int				create_paths(void)
{
	t_link	*path;

	path = NULL;
	add_path(&path, ft_s()->root);
	find_paths(ft_s()->root, path);
	if (ft_s()->paths == NULL)
		return (0);
	assign_weight();
	return (1);
}
