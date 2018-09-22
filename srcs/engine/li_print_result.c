/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 17:27:29 by fchanal           #+#    #+#             */
/*   Updated: 2018/04/19 17:28:17 by fchanal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_engine.h"

void	li_print_result(t_data *data, t_bfs *bfs)
{
	int	max_turn;
	int	turn;
	int	ants;
	int	degressive;

	max_turn = data->nbr_ants + (bfs->size - 2);
	turn = 0;
	while (turn < max_turn)
	{
		degressive = turn;
		ants = 1;
		while (degressive >= 0)
		{
			if (degressive < (int)(bfs->size - 1))
				ft_printf("L%d-%s ", ants, bfs->road[degressive + 1]);
			--degressive;
			++ants;
			if (ants > data->nbr_ants)
				break ;
		}
		ft_printf("\n");
		++turn;
	}
}
