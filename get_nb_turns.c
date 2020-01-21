/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_turns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 17:58:27 by plogan            #+#    #+#             */
/*   Updated: 2017/06/28 19:38:37 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int	get_turns(t_path *paths)
{
	int		ret;

	ret = 0;
	if (!paths)
		return (-1);
	while (paths)
	{
		if (ret < paths->traffic)
			ret = paths->traffic;
		paths = paths->next;
	}
	return (ret);
}

static void	add_to_lowest_weight(t_path *paths)
{
	int		best_weight;
	t_path	*best_path;

	if (!paths)
		return ;
	best_path = paths;
	best_weight = paths->temp_weight;
	paths = paths->next;
	while (paths)
	{
		if (paths->temp_weight < best_weight)
		{
			best_weight = paths->temp_weight;
			best_path = paths;
		}
		paths = paths->next;
	}
	best_path->traffic++;
	best_path->temp_weight++;
}

int			get_nb_turns(t_path *paths)
{
	int		nb_ants;
	t_path	*temp_paths;

	temp_paths = paths;
	nb_ants = ft_s()->nb_ants;
	while (temp_paths)
	{
		temp_paths->traffic = 0;
		temp_paths->temp_weight = temp_paths->weight;
		temp_paths = temp_paths->next;
	}
	while (nb_ants > 0)
	{
		add_to_lowest_weight(paths);
		nb_ants--;
	}
	return (get_turns(paths)); //do
}
