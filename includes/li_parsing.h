/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdjeghba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 18:02:22 by sdjeghba          #+#    #+#             */
/*   Updated: 2018/04/20 13:05:02 by sdjeghba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LI_PARSING_H
# define LI_PARSING_H

# include "libft2.h"
# include "get_next_line.h"

typedef struct		s_room
{
	char			*room;
	struct s_room	*next;
}					t_room;

typedef struct		s_pipe
{
	char			*enter;
	char			*exit;
	struct s_pipe	*next;
}					t_pipe;

typedef struct		s_data
{
	int				nbr_ants;
	int				nbr_rooms;
	int				step;
	char			*str;
	char			*line;
	char			*start;
	char			*end;
	t_room			*rooms;
	t_pipe			*pipes;
}					t_data;

void				puterror(void);

/*
**	handle_rooms.c
*/

t_room				*add_room(t_data *d);
void				pushback_room(t_room **rooms, t_data *d);
int					room_len(t_room *rooms);
void				free_rooms(t_room **list);
int					check_double_room(t_room *room);

/*
**    get_datas.c
*/

void				get_parse_map(t_data *d);
int					get_nbr_ants(t_data *d);
int					get_start_end(t_data *d, int value);
int					get_tube(t_data *d);
int					get_room(t_data *d);

/*
**    hamdle_pipes.c
*/

int					check_format(t_data *d);
t_pipe				*add_pipe(t_data *d);
void				pushback_pipe(t_pipe **pipes, t_data *d);
int					check_connection(t_room *rooms, t_pipe *pipes);
void				free_pipes(t_pipe **pipes);

#endif
