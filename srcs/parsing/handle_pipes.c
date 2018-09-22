/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 02:01:18 by salemdjeg         #+#    #+#             */
/*   Updated: 2018/04/20 13:06:21 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_parsing.h"

int			check_format(t_data *d)
{
	char	*sp1;
	char	*sp2;

	if (d->line[0] == 'L' || !(sp1 = ft_strchr(d->line, ' ')) ||
			!(sp2 = ft_strchr(sp1 + 1, ' ')) || !ft_strisdigit(sp2 + 1) ||
			!ft_strnisdigit(sp1 + 1, sp2 - (sp1 + 1)))
		return (1);
	return (0);
}

t_pipe		*add_pipe(t_data *d)
{
	t_pipe	*new;
	int		i;

	i = 0;
	while (d->line[i] && d->line[i] != '-')
		i++;
	if (!(new = malloc(sizeof(t_pipe))))
		return (NULL);
	new->enter = ft_strsub(d->line, 0, i);
	new->exit = ft_strsub(d->line, i + 1, ft_strlen(d->line) - i);
	new->next = NULL;
	return (new);
}

void		pushback_pipe(t_pipe **pipes, t_data *d)
{
	t_pipe	*tmp;

	tmp = *pipes;
	if (!tmp)
		*pipes = add_pipe(d);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = add_pipe(d);
	}
}

void		free_pipes(t_pipe **pipes)
{
	t_pipe	*tmp;
	t_pipe	*now;

	tmp = *pipes;
	now = *pipes;
	while (now->next)
	{
		tmp = now->next;
		ft_strlen(now->enter) ? ft_strdel(&now->enter) : 0;
		ft_strlen(now->exit) ? ft_strdel(&now->exit) : 0;
		now = tmp;
	}
}

int			check_connection(t_room *rooms, t_pipe *pipes)
{
	t_room	*tmp_r;
	t_pipe	*tmp_p;
	int		found_ent;
	int		found_ex;

	found_ent = 0;
	found_ex = 0;
	tmp_r = rooms;
	tmp_p = pipes;
	while (tmp_p)
	{
		while (tmp_r)
		{
			!ft_strcmp(tmp_p->enter, tmp_r->room) ? found_ent++ : 0;
			!ft_strcmp(tmp_p->exit, tmp_r->room) ? found_ex++ : 0;
			tmp_r = tmp_r->next;
		}
		if (found_ent < 1 || found_ex < 1)
			return (1);
		found_ent = 0;
		found_ex = 0;
		tmp_r = rooms;
		tmp_p = tmp_p->next;
	}
	return (0);
}
