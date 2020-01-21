/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_on.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 16:19:02 by plogan            #+#    #+#             */
/*   Updated: 2017/06/28 15:10:58 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	display_basics(void)
{
	t_room	*start;
	t_room	*end;

	end = ft_s()->rooms;
	start = ft_s()->rooms;
	while (start->type != 0)
		start = start->next;
	while (end->type != 1)
		end = end->next;
	ft_printf("--------- BASICS ---------\n");
	ft_printf("| #ants : %-15d|\n", ft_s()->nb_ants);
	ft_printf("| #rooms: %-15d|\n", ft_s()->nb_rooms);
	ft_printf("| start : %-15s|\n", start->name);
	ft_printf("| end   : %-15s|\n", end->name);
}

static void	display_rooms(void)
{
	t_room	*temp_room;
	t_tube	*temp_tube;

	temp_room = ft_s()->rooms;
	while (temp_room)
	{
		ft_printf("--------- %-6s ---------\n", temp_room->name);
		ft_printf("| index: %-16d|\n", temp_room->index);
		temp_tube = ft_s()->tubes;
		while (temp_tube)
		{
			if (temp_tube->room1->name == temp_room->name)
				ft_printf("| linked to: %-12s|\n", temp_tube->room2->name);
			if (temp_tube->room2->name == temp_room->name)
				ft_printf("| linked to: %-12s|\n", temp_tube->room1->name);
			temp_tube = temp_tube->next;
		}
		temp_room = temp_room->next;
	}
	ft_printf("--------- PATHS  ---------\n");
}

void		display_on(void)
{
	display_basics();
	display_rooms();
	display_paths();
}
