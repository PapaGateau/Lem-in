/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 18:19:07 by plogan            #+#    #+#             */
/*   Updated: 2017/06/26 20:54:23 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	assign_start(int *mode, char *line)
{
	if (*mode == 0)
		*mode = ERROR;
	else if (ft_s()->start_found)
		*mode = END_PARSE;	
	else
	{	
		if (get_next_line(0, &line) <= 0 || !ft_room_list_push(line, 0)) 
			*mode = ERROR;
		ft_s()->start_found = 1;
	}
}

static void	assign_end(int *mode, char *line)
{
	if (*mode == 0)
		*mode = ERROR;
	else if (ft_s()->end_found)
		*mode = END_PARSE;
	else
	{
		if (get_next_line(0, &line) <= 0 || !ft_room_list_push(line, 1)) 
			*mode = ERROR;
		ft_s()->end_found = 1;
	}
}

void		check_comment(char *line, int *mode)
{
	if (!ft_strcmp(line, "##start"))
		assign_start(mode, line);
	else if (!ft_strcmp(line, "##end"))
		assign_end(mode, line);
	else if (!ft_strcmp(line, "#display"))
		ft_s()->display = 1;
}
