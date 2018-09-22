/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_find_best_road.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 17:17:59 by fchanal           #+#    #+#             */
/*   Updated: 2018/04/19 17:47:55 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_engine.h"

void	check_new_road(t_data *data, t_bfs *bfs, char **stack_room_cp, \
		char **stack_room)
{
	size_t	tmp;
	char	**init;

	if ((tmp = road_size(stack_room_cp, stack_room)) < bfs->size || \
			bfs->size == 0)
	{
		bfs->size = tmp;
		clear_bfs_road(data, bfs);
		init = bfs->road;
		while (stack_room_cp <= stack_room)
		{
			*bfs->road = *stack_room_cp;
			++bfs->road;
			++stack_room_cp;
		}
		bfs->road = init;
	}
}

bool	never_went_here(char *test_room, char **stack_room_cp, \
		char **stack_room)
{
	while (stack_room_cp <= stack_room)
	{
		if (ft_strequ(test_room, *stack_room_cp))
			return (false);
		++stack_room_cp;
	}
	return (true);
}

bool	check_if_end(t_data *data, t_bfs *bfs, char **stack_room_cp, \
		char ***stack_room)
{
	if (ft_strequ(**stack_room, data->end))
	{
		check_new_road(data, bfs, stack_room_cp, *stack_room);
		--*stack_room;
		return (1);
	}
	return (0);
}

void	engine(t_data *data, t_bfs *bfs, char **stack_room_cp, \
		char ***stack_room)
{
	t_pipe		*pipes;

	if (check_if_end(data, bfs, stack_room_cp, stack_room))
		return ;
	pipes = data->pipes;
	while (pipes)
	{
		if (ft_strequ(**stack_room, pipes->enter) && \
				never_went_here(pipes->exit, stack_room_cp, *stack_room))
		{
			*++*stack_room = pipes->exit;
			engine(data, bfs, stack_room_cp, stack_room);
		}
		else if (ft_strequ(**stack_room, pipes->exit) && \
				never_went_here(pipes->enter, stack_room_cp, *stack_room))
		{
			*++*stack_room = pipes->enter;
			engine(data, bfs, stack_room_cp, stack_room);
		}
		pipes = pipes->next;
	}
	--*stack_room;
}

t_bfs	li_find_bfs(t_data *data)
{
	t_bfs		bfs;
	char		**stack_room;
	char		**delete_me;

	bfs.size = 0;
	if (!(bfs.road = (char**)malloc(sizeof(*bfs.road) * data->nbr_rooms)))
		li_exit_alloc_failure();
	if (!(stack_room = (char**)malloc(sizeof(*stack_room) * data->nbr_rooms)))
		li_exit_alloc_failure();
	delete_me = stack_room;
	*stack_room = data->start;
	engine(data, &bfs, stack_room, &stack_room);
	free((void*)delete_me);
	return (bfs);
}
