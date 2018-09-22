/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeghba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:07:15 by sdjeghba          #+#    #+#             */
/*   Updated: 2018/04/19 18:07:18 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_engine.h"

void			puterror(void)
{
	ft_putendl("ERROR");
	exit(0);
}

void			init_struct(t_data *d)
{
	d->nbr_ants = 0;
	d->nbr_rooms = 0;
	d->step = 0;
	d->str = NULL;
	d->line = NULL;
	d->start = NULL;
	d->end = NULL;
	d->rooms = NULL;
	d->pipes = NULL;
}

int				main(void)
{
	t_bfs		bfs;
	t_data		data;

	init_struct(&data);
	get_parse_map(&data);
	bfs = li_find_bfs(&data);
	if (!bfs.size)
	{
		ft_dprintf(2, "ERROR\n");
		return (1);
	}
	ft_putendl(data.str);
	li_print_result(&data, &bfs);
	free((void*)bfs.road);
	free_rooms(&data.rooms);
	free_pipes(&data.pipes);
	return (0);
}
