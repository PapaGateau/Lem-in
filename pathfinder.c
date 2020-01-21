/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 16:26:39 by plogan            #+#    #+#             */
/*   Updated: 2017/06/28 19:43:43 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

//REMOVE
void		print_final_paths()
{
	t_path	*temp;
	t_link	*temp_path;

	temp = ft_s()->paths;
	while (temp)
	{
		ft_printf("weight: %d\ntraffic: %d\n", temp->weight, temp->traffic);
		temp_path = temp->path;
		while (temp_path)
		{
			ft_printf("%s->", temp_path->room->name);
			temp_path = temp_path->next;
		}
		write(1, "\n", 1);
		temp = temp->next;
	}
}

static int	paths_intersect(t_path *main_paths, t_link *new_path)
{
	t_link	*path;
	t_link	*temp_path;

	if (!main_paths)
		return (0);
	while (main_paths)
	{
		path = main_paths->path;
		if (path->room->index == new_path->room->index &&
			path->next->room->index == new_path->next->room->index &&
			new_path->next->next == NULL && path->next->next == NULL)
			return (1);
		path = path->next;
		while (path->next)
		{
			temp_path = new_path;
			while (temp_path)
			{
				if (path->room->index == temp_path->room->index)
					return (1);
				temp_path = temp_path->next;
			}
			path = path->next;
		}
		main_paths = main_paths->next;
	}
	return (0);
}

static void	set_weight(t_path *paths)
{
	t_link	*path;

	while (paths)
	{
		path = paths->path;
		while (path)
		{
			path = path->next;
			paths->weight++;
		}
		paths = paths->next;
	}
}

static void	find_solution(t_path **final_paths, t_path **actual_paths)
{
	t_path	*temp_path;
	int		nb_turns;
	
	set_weight(*actual_paths);
	nb_turns = get_nb_turns(*actual_paths);
	if (nb_turns != -1 && ft_s()->nb_turns == 0)
	{
//	printf("*a_p->traffic: %d\n", (*actual_paths)->traffic);
		ft_s()->nb_turns = nb_turns;
		save_paths(final_paths, *actual_paths);
	}
	else if (nb_turns != -1 && nb_turns < ft_s()->nb_turns)
	{
//	printf("*a_p->traffic: %d\n", (*actual_paths)->traffic);
//		write(1, "yo\n", 3);
		free_paths(final_paths);
//		write(1, "yo\n", 3);
		ft_s()->nb_turns = nb_turns;
		save_paths(final_paths, *actual_paths);
	}
	temp_path = ft_s()->paths;
	while (temp_path)
	{
		if (!paths_intersect(*actual_paths, temp_path->path))
		{
			save_path(actual_paths, temp_path->path);
			find_solution(final_paths, actual_paths);
		}
		temp_path = temp_path->next;
	}
	remove_last_paths(actual_paths);
}

void		pathfinder(void)
{
	t_path	*final_paths;
	t_path	*actual_paths;

	final_paths = NULL;
	actual_paths = NULL;
	find_solution(&final_paths, &actual_paths);
	print_final_paths();
}
