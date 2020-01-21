/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plogan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 19:11:05 by plogan            #+#    #+#             */
/*   Updated: 2017/06/23 19:04:55 by plogan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	check_first_line(char *line, int *mode)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(line);
	while (i < len)
	{
		if (!ft_isdigit(line[i]))
			*mode = ERROR;
		i++;
	}
	if (*mode != ERROR)
	{
		ft_s()->nb_ants = ft_atoi(line);
		if (!ft_s()->nb_ants)
			*mode = ERROR;
		else
			*mode = 1;
	}
}
