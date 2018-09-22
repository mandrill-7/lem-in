/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnisdigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salemdjeghbala <marvin@42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 01:54:46 by salemdjeg         #+#    #+#             */
/*   Updated: 2018/04/17 01:55:40 by salemdjeg        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft2.h"

int			ft_strnisdigit(char *str, int n)
{
	int i;

	i = 0;
	if (!(*str))
		return (0);
	while (*str && i < n)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
		i++;
	}
	return (1);
}
