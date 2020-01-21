/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_room_list_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 19:52:36 by plogan            #+#    #+#             */
/*   Updated: 2017/06/27 18:40:23 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int		check_duplicate(t_room *room)
{
	t_room	*temp;
	char	*current;

	temp = ft_s()->rooms;
	current = room->name;
	while (temp->next)
	{
		if (!ft_strcmp(temp->name, current))
		{
			free(room->name);
			free(room);
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}

static t_room	*ft_create_room(int type, char *line)
{
	t_room	*new;
	int		i;

	i = 0;
	if (!(new = (t_room *)malloc(sizeof(t_room))))
		return (new);
	new->index = ft_s()->nb_rooms++;
	new->type = type;
	new->content = 0;
	new->links = NULL;
	new->next = NULL;
	while (line[i] != ' ')
		i++;
	if (!(new->name = ft_strsub(line, 0, i++)))
		return (NULL);
	new->x = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	new->y = ft_atoi(&line[i++]);
	return (new);
}

static int		check_line(char *line)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (line[i] != ' ')
		i++;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ')
			return (0);
		i++;
	}
	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' && (line[i + 1] == '\0' || (line[i + 1] == ' ')))
			return (0);
		if (line[i] == ' ')
			count++;
		i++;
	}
	if (count != 2)
		return (0);
	return (1);
}

int				ft_room_list_push(char *line, int type)
{
	t_room	*new;

	if (ft_strlen(line) < 5 || !check_line(line))
		return (0);
	if (ft_s()->rooms == NULL)
	{
		if (!(ft_s()->rooms = ft_create_room(type, line)))
			return (0);
		return (1);
	}
	new = ft_s()->rooms;
	while (new->next != NULL)
		new = new->next;
	new->next = ft_create_room(type, line);
	if (!new->next || !check_duplicate(new->next))
	{
		new->next = NULL;
		return (0);
	}
	return (1);
}
