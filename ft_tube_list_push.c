/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tube_list_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 16:46:33 by plogan            #+#    #+#             */
/*   Updated: 2017/06/26 20:54:21 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int		check_line(char *line)
{
	int		i;
	int		count;
	int		size;

	size = ft_strlen(line);
	count = 0;
	i = 0;
	while (line[i])
	{
		if (i != 0 && i != size - 1 && line[i] == '-')
			count++;
		i++;
	}
	if (count != 1)
		return (0);
	return (1);
}

static int		assign_names(t_tube *new, char *name1, char *name2)
{
	t_room	*temp;

	temp = ft_s()->rooms;
	while (temp)
	{
		if (!ft_strcmp(name1, temp->name))
			new->room1 = temp;
		if (!ft_strcmp(name2, temp->name))
			new->room2 = temp;
		temp = temp->next;
	}
	if (!new->room1 || !new->room2)
	{
		free(name1);
		free(name2);
		return (0);
	}
	return (1);
}

static t_tube	*ft_create_tube(char *line)
{
	t_tube	*new;
	char	*name1;
	char	*name2;
	int		i;

	i = 0;
	if (!(new = (t_tube *)malloc(sizeof(t_tube))))
		return (new);
	new->room1 = NULL;
	new->room2 = NULL;
	new->next = NULL;
	while (line[i] != '-')
		i++;
	if (!(name1 = ft_strsub(line, 0, i++)))
		return (NULL);
	if (!(name2 = ft_strdup(line + i)))
		return (NULL);
	if (!ft_strcmp(name1, name2) || !assign_names(new, name1, name2))
	{
		free(new);
		return (NULL);
	}
	free(name1);
	free(name2);
	return (new);
}

static int		check_duplicate(t_tube *tube)
{
	t_tube	*temp;

	temp = ft_s()->tubes;
	while (temp->next)
	{
		if ((!ft_strcmp(tube->room1->name, temp->room1->name) &&
				!ft_strcmp(tube->room2->name, temp->room2->name)) ||
				(!ft_strcmp(tube->room1->name, temp->room2->name) &&
				 !ft_strcmp(tube->room2->name, temp->room1->name)))
		{
			free(tube);
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}

int				ft_tube_list_push(char *line)
{
	t_tube	*new;

	if (ft_strlen(line) < 3 || !check_line(line))
		return (0);
	if (ft_s()->tubes == NULL)
	{
		if (!(ft_s()->tubes = ft_create_tube(line)))
			return (0);
		return (1);
	}
	new = ft_s()->tubes;
	while (new->next != NULL)
		new = new->next;
	new->next = ft_create_tube(line);
	if (!new->next || !check_duplicate(new->next))
	{
		new->next = NULL;
		return (0);
	}
	return (1);
}
