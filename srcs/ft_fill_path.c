/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_dawe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:44:09 by rkrief            #+#    #+#             */
/*   Updated: 2018/04/23 16:01:17 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int     ft_check_ifexist(char *room, char *path)
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


char	*ft_get_room(char *room, char *link)
{
	int 	i;
	int 	j;
	int 	k;
	char	*res;

	k = 0;
	i = 0;
	if (room == NULL || link == NULL)
		return (0);
	while (link[i] != '-')
		i++;
	res = ft_strndup(link, i++);
	k = ft_strequ(res, room);
	if (!k)
		return (res);
	ft_strdel(&res);
	j = i;
	while (link[i])
		i++;
	res = (char*)malloc(sizeof(char) * (i - j + 1));
	i = 0;
	while (link[j])
	{
		res[i] = link[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}


int		ft_find_room_intube(char *room, char *link)
{
	int 	i;
	int 	j;
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


int		ft_find_nbroom(t_ants *info)
{
	int	nb_rooms;

	nb_rooms = 0;
	while (info->names[nb_rooms])
		nb_rooms++;
	nb_rooms--;
	if (nb_rooms < 0)
		return (0);
	info->nb_room = nb_rooms;
	return (nb_rooms);
}


char	*ft_findlink(t_ants info, char **allpath)
{
	int 	nb_rooms;
	char	**room;
	char	*path;
	int		i;
	int		j;

	i = 0;
	j = 0;
	room[j] = info.start;
	path = info.start;
	if (!(nb_rooms = ft_find_nbroom(&info)))
		return (0);
	while (nb_rooms)
	{
		while (info.tubes[i])
		{
			if (ft_find_room_intube(room, info.tubes[i]))
			{
				if (ft_check_ifexist(ft_get_room(room, info.tubes[i++]), path))
					continue ;
				i--;	
				path = ft_strjoin(ft_strjoin(path, "-"), ft_get_room(room, info.tubes[i]));
				room = ft_get_room(room, info.tubes[i]);
				ft_putendl(room);

				if (ft_strequ(room, info.end) /*&& !ft_check_ifpath(path, allpath)*/)
					return (path);
//				if (room == info.end && ft_check_ifpath(path, allpath))
//				{
//						
//				}
				break ;
			}
			i++;
		}
		i = 0;
		nb_rooms--;
	}
	return (path);
}


char	*ft_find_path(t_ants info)
{
	char	*conexion;
	char	**allpath;
	int		i;

	i = 0;
	allpath = (char**)ft_memalloc(sizeof(char*) * (info.nb_room + 1));
//	while (1)
//	{
		if (!(conexion = ft_findlink(info, allpath)))
			return(NULL);
//		allpath[i] = connexion;
//		i++;
//	}
	return (conexion);	
}


char	**ft_createtab(int	nb_ant)
{
	char **tab;

	tab = (char**)malloc(sizeof(char*) * (nb_ant + 1));
	return (tab);
}

void	ft_fill_path(t_ants info)
{
	int 	i;
	char	**ant_path;
	//	char	*path;

	i = 0;
//	allpath=0;
	ant_path = ft_createtab(info.nb_ant);
	ft_putendl(ft_find_path(info));
}
