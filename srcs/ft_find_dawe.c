/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_dawe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:44:09 by rkrief            #+#    #+#             */
/*   Updated: 2018/04/19 19:52:04 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"





char	**ft_findlink(s_ants info)
{
	int nb_rooms;

	nb_rooms = 0;
	while (info.names[nb_rooms])
		nb_rooms++;
	nb_rooms--;
	if (nb_rooms < 0)
		return (NULL);
	while (nb_rooms)
	{
		ft_find_room_intube(
	}
}


char	**ft_find_path(s_ants info, char **allpath)
{
	char	**conexion;

	connexion = ft_findlink(info);
}


char	**ft_createtab(int	nb_ant)
{
	char **tab;

	tab = (char**)malloc(sizeof(char*) * (nb_ant + 1));
	return (tab);
}

void	ft_fill_path(s_ants info)
{
	int 	i;
	char	**ant_path;
	char	*path;
	char	**allpath;

	i = 0;
	ant_path = ft_createtab(info.nb_ant);
	while (i < info.nb_ant)
	{
		if ((path = ft_find_path(info, allpath)))
		{
			if (ft_exist_path(path, tab, info))
			{
				ft_add_path(path, allpath);
				continue ;
			}
			ant_path[i] = path;
		}
		i++;
	}
}
