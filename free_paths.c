/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 17:41:42 by plogan            #+#    #+#             */
/*   Updated: 2017/06/28 19:43:38 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		save_paths(t_path **dest, t_path *src)
{
	while (src)
	{
		save_path(dest, src->path);
		src = src->next;
	}
}

void		free_paths(t_path **paths)
{
	t_link	*path;
	t_path	*copy1;
	t_path	*copy2;

	copy1 = *paths;
	while (*paths)
	{
		path = (*paths)->path;
		while (path)
		{
			free(path);
			path = path->next;
		}
		(*paths)->path = NULL;
		copy2 = *paths;
		free(*paths);
		*paths = copy2->next;
	}
	copy1 = NULL;
	*paths = NULL;
}
