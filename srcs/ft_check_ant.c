/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 09:17:45 by alecott           #+#    #+#             */
/*   Updated: 2018/02/28 19:13:18 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		ft_check_ant(t_ants *info, char *room)
{
	if (ft_strequ(room, info->end) ||
	info->rooms_state[ft_room_number(info, room)] == 0)
		return (1);
	return (0);
}
