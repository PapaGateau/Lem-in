/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_room_tube.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 19:24:59 by plogan            #+#    #+#             */
/*   Updated: 2017/06/26 19:57:04 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void		check_room_tube(char *line, int *mode)
{
	if (*mode == 1 && !ft_strchr(line, '-'))
	{
		if (!ft_room_list_push(line, 2))
			*mode = ERROR;
	}
	else
		*mode = 2;
	if (*mode == 2 && (!ft_s()->start_found || !ft_s()->end_found))
	{
		*mode = ERROR;
		return ;
	}
	if (*mode == 2 && !ft_strchr(line, ' '))
	{
		if (!ft_tube_list_push(line))
			*mode = END_PARSE;
	}	
}
