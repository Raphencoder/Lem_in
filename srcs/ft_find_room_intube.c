/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:44:09 by rkrief            #+#    #+#             */
/*   Updated: 2018/04/30 18:14:50 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		ft_find_room_intube(char *room, char *link)
{
	int		i;
	int		j;
	int		k;
	char	*res;

	i = 0;
	j = 0;
	if (room == NULL || link == NULL)
		return (0);
	while (link[i] != '-')
		i++;
	res = ft_strndup(link, i++);
	k = ft_strequ(res, room);
	ft_strdel(&res);
	if (k)
		return (1);
	while (link[i] && room[j])
	{
		if (link[i] != room[j])
			return (0);
		i++;
		j++;
	}
	return (1);
}
