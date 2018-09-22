/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 01:54:27 by salemdjeg         #+#    #+#             */
/*   Updated: 2018/04/20 01:58:07 by salemdjeg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_parsing.h"

int			room_len(t_room *rooms)
{
	t_room	*tmp;
	int		i;

	tmp = rooms;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_room		*add_room(t_data *d)
{
	t_room	*new;
	int		i;

	i = 0;
	while (d->line[i] && d->line[i] != ' ')
		i++;
	if (!(new = malloc(sizeof(t_room))))
		return (NULL);
	new->room = ft_strsub(d->line, 0, i);
	new->next = NULL;
	return (new);
}

void		pushback_room(t_room **rooms, t_data *d)
{
	t_room	*tmp;

	tmp = *rooms;
	if (!tmp)
		*rooms = add_room(d);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_room(d);
	}
}

int			check_double_room(t_room *room)
{
	t_room	*tmp;
	t_room	*now;

	tmp = room->next;
	now = room;
	!room ? puterror() : 0;
	while (now->next)
	{
		while (tmp)
		{
			if (!ft_strcmp(now->room, tmp->room))
				return (1);
			tmp = tmp->next;
		}
		now = now->next;
		tmp = now;
		tmp = (tmp->next ? tmp->next : 0);
	}
	tmp = room;
	return (0);
}

void		free_rooms(t_room **list)
{
	t_room	*tmp;
	t_room	*now;

	tmp = *list;
	now = *list;
	while (now->next)
	{
		tmp = now->next;
		ft_strlen(now->room) ? ft_strdel(&now->room) : 0;
		now = tmp;
	}
}
