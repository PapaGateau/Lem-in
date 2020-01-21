/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:53:57 by plogan            #+#    #+#             */
/*   Updated: 2017/06/28 15:22:01 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		display_paths(void)
{
	t_path	*temp_root;
	t_link	*temp_path;

	temp_root = ft_s()->paths;
	while (temp_root)
	{
		temp_path = temp_root->path;
		while (temp_path)
		{
			ft_printf("%s", temp_path->room->name);
			if (!temp_path->next)
				write(1, "\n", 1);
			else
				write(1, "->", 2);
			temp_path = temp_path->next;
		}
		ft_printf("length: %d\n", temp_root->weight);
		temp_root = temp_root->next;
	}
}
