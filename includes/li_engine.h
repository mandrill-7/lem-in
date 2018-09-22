/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_engine.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 17:30:46 by fchanal           #+#    #+#             */
/*   Updated: 2018/04/19 17:46:20 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LI_ENGINE_H
# define LI_ENGINE_H

# include "libft.h"
# include "ft_printf.h"
# include "li_parsing.h"

typedef struct s_bfs	t_bfs;

struct					s_bfs
{
	char				**road;
	size_t				size;
};

t_bfs					li_find_bfs(t_data *data);
void					li_print_result(t_data *data, t_bfs *bfs);

void					li_exit_alloc_failure(void);
size_t					road_size(char **stack_room_cp, char **stack_room);
void					clear_bfs_road(t_data *data, t_bfs *bfs);

#endif
