/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 17:31:49 by plogan            #+#    #+#             */
/*   Updated: 2017/06/28 19:43:36 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		free_singleton(void)
{
	//free tubes
	//free rooms > free names of rooms
	//free singleton items
	free(ft_s());
}

int			main(void)
{
	int		ret;
	char	*line;
	int		mode;

	mode = 0;
	while (mode < END_PARSE && (ret = get_next_line(0, &line)) > 0)
	{
		if (!ft_strlen(line))
			mode = END_PARSE;
		if (line[0] == 'L')
			mode = END_PARSE;
		else if (line[0] == '#')
			check_comment(line, &mode);
		else if (mode == 0)
			check_first_line(line, &mode);
		else if (mode == 1 || mode == 2)
			check_room_tube(line, &mode);
	}
	if (mode == ERROR || mode < 2 || !ft_s()->start_found ||
			!ft_s()->end_found || !create_path_tree())
		write(2, "ERROR\n", 6);
	else
	{
		if (ft_s()->display)
			display_on();
	//	need to check if coordinates are valid
		pathfinder();
	}
	//	free path tree, tubes, rooms(+name) and singleton struct items
	free_singleton();
	free(line);
}
