/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path_tree.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 16:57:58 by plogan            #+#    #+#             */
/*   Updated: 2017/06/27 18:40:24 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

// make links between rooms, from start, once per link
// make struct for ants, create one for each with its index and name
// make struct for weight of each path, assign accordingly
// on a turn basis, while increasing weight of paths (+1 per ant that will 
// 	take it, excluding paths that intersect), advance ants one by one through 
// 	lowest weighted path. when no more ants can advance, print moves and reset

static void	create_new_link(t_room *root, t_room *room)
{
	t_link	*new;
	t_link	*temp;

	temp = root->links;
	if (!(new = (t_link *)malloc(sizeof(t_link))))
		return ;
	new->room = room;
	new->next = NULL;
	if (!root->links)
		root->links = new;
	else
	{
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

static void	fill_tree()
{
	t_room	*room;
	t_tube	*tube;

	room = ft_s()->rooms;
	while (room)
	{
		tube = ft_s()->tubes;
		while (tube)
		{
			if (tube->room1->name == room->name)
				create_new_link(room, tube->room2);
			if (tube->room2->name == room->name)
				create_new_link(room, tube->room1);
			tube = tube->next;
		}
		room = room->next;
	}
}

int			create_path_tree(void)
{
	t_room	*start;
	
	start = ft_s()->rooms;
	if (!ft_s()->tubes)
		return (0);
	while (start->type != 0)
		start = start->next;
	ft_s()->root = start;
	fill_tree();
	if (!create_paths())
		return (0);
	return (1);
}
