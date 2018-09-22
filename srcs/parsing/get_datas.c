/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_datas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 02:00:49 by salemdjeg         #+#    #+#             */
/*   Updated: 2018/04/20 13:06:12 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_parsing.h"

int			get_nbr_ants(t_data *d)
{
	if (!ft_strisdigit(d->line) || d->step > 0)
		return (1);
	d->nbr_ants = ft_atoi(d->line);
	d->nbr_ants <= 0 || d->nbr_ants >= 2147483647 ? puterror() : 0;
	d->step = 1;
	return (0);
}

int			get_start_end(t_data *d, int value)
{
	char	*sp1;

	ft_strlen(d->line) ? ft_strdel(&d->line) : 0;
	while (get_next_line(0, &d->line) >= 0)
	{
		if ((d->line[0] != '#' && ft_strcmp(d->line, "##start") &&
			ft_strcmp(d->line, "##end")))
			break ;
		d->str = ft_strjoin_free_s1(d->str, d->line);
		d->str = ft_strjoin_free_s1(d->str, "\n");
	}
	!ft_strcmp(d->line, "##start") && value ? get_start_end(d, 0) : 0;
	!ft_strcmp(d->line, "##end") && !value ? get_start_end(d, 1) : 0;
	get_room(d);
	if (check_format(d))
		return (1);
	sp1 = ft_strchr(d->line, ' ');
	!value && d->start ? ft_strdel(&d->start) : 0;
	value && d->end ? ft_strdel(&d->end) : 0;
	d->start = (!value ? ft_strsub(d->line, 0, sp1 - d->line) : d->start);
	d->end = (value ? ft_strsub(d->line, 0, sp1 - d->line) : d->end);
	d->str = ft_strjoin_free_s1(d->str, d->line);
	d->str = ft_strjoin_free_s1(d->str, "\n");
	return (0);
}

int			get_tube(t_data *d)
{
	char	*tmp;
	int		i;
	int		dash;

	i = -1;
	dash = 0;
	while (d->line[++i])
		d->line[i] == '-' ? dash++ : 0;
	tmp = ft_strchr(d->line, '-');
	if (d->line[0] == 'L' || d->line[0] == '-' ||
			d->line[ft_strlen(d->line) - 1] == '-' || ft_strchr(d->line, ' ') ||
			ft_strchr(d->line, '\t') || tmp[1] == '-' || dash != 1)
		return (1);
	d->step = 2;
	if (!d->pipes)
		d->pipes = add_pipe(d);
	else
		pushback_pipe(&d->pipes, d);
	return (0);
}

int			get_room(t_data *d)
{
	char	*str;
	int		i;

	i = 0;
	str = NULL;
	if (check_format(d))
		return (1);
	while (d->line[i] && d->line[i] != ' ')
		i++;
	str = ft_strsub(d->line, 0, i);
	if (!d->rooms)
		d->rooms = add_room(d);
	else
		pushback_room(&d->rooms, d);
	ft_strlen(str) ? ft_strdel(&str) : 0;
	return (0);
}

void		get_parse_map(t_data *d)
{
	int		ret;

	while ((ret = get_next_line(0, &d->line)) > 0)
	{
		d->str = ft_strjoin_free_s1(d->str, d->line);
		d->str = ft_strjoin_free_s1(d->str, "\n");
		if (d->line[0] == '#' && ft_strcmp(d->line, "##start") &&
				ft_strcmp(d->line, "##end"))
			;
		else if (!ft_strcmp(d->line, "##start") && d->step == 1)
			get_start_end(d, 0) ? puterror() : 0;
		else if (!ft_strcmp(d->line, "##end") && d->step == 1)
			get_start_end(d, 1) ? puterror() : 0;
		else if (ft_strchr(d->line, '-'))
			get_tube(d) ? puterror() : 0;
		else if (ft_strchr(d->line, ' ') && d->step == 1)
			get_room(d) ? puterror() : 0;
		else
			get_nbr_ants(d) ? puterror() : 0;
		ft_strlen(d->line) ? ft_strdel(&d->line) : 0;
	}
	d->nbr_rooms = room_len(d->rooms);
	!d->str || !d->start || !d->end || !ft_strcmp(d->start, d->end) ||
		!d->nbr_rooms || d->step != 2 || check_double_room(d->rooms) ||
		check_connection(d->rooms, d->pipes) ? puterror() : 0;
}
