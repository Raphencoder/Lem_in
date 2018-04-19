/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_room_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 14:52:02 by alecott           #+#    #+#             */
/*   Updated: 2018/02/28 14:54:36 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		ft_room_number(t_ants *info, char *room)
{
	int		i;

	i = 0;
	while (info->names[i])
	{
		if (ft_strequ(info->names[i], room))
			return (i);
		i++;
	}
	return (0);
}
