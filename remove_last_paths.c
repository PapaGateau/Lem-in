/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_last_paths.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 17:38:32 by plogan            #+#    #+#             */
/*   Updated: 2017/06/28 17:40:46 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	remove_last_paths(t_path **paths)
{
	t_path	*temp_path;

	temp_path = *paths;
	if (!(*paths))
		return ;
	else if (!(*paths)->next)
	{
		free(*paths);
		*paths = NULL;
		return ;
	}
	while (temp_path->next->next)
		temp_path = temp_path->next;
	free(temp_path->next);
	temp_path->next = NULL;
}
