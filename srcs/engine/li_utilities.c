/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 17:29:20 by fchanal           #+#    #+#             */
/*   Updated: 2018/04/19 17:45:30 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_engine.h"

void	li_exit_alloc_failure(void)
{
	ft_dprintf(2, "Allocation failure premature exit\n");
	exit(1);
}

size_t	road_size(char **stack_room_cp, char **stack_room)
{
	size_t		len;

	len = 0;
	while (stack_room_cp <= stack_room)
	{
		++len;
		++stack_room_cp;
	}
	return (len);
}

void	clear_bfs_road(t_data *data, t_bfs *bfs)
{
	int		i;

	i = 0;
	while (i < data->nbr_rooms)
	{
		bfs->road[i] = NULL;
		++i;
	}
}
