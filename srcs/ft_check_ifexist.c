/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:44:09 by rkrief            #+#    #+#             */
/*   Updated: 2018/04/30 18:10:27 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		ft_check_ifexist(char *room, char *path)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (path[i])
	{
		if (room[j] == path[i])
		{
			while (path[i] != '-' && room[j] && room[j] == path[i])
			{
				j++;
				i++;
			}
			if (!room[j] && (path[i] == '-' || !path[i]))
				return (1);
		}
		j = 0;
		while (path[i] && path[i] != '-')
			i++;
		i++;
	}
	return (0);
}
