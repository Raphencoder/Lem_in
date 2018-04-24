/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:44:09 by rkrief            #+#    #+#             */
/*   Updated: 2018/04/25 00:36:49 by Raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"


int     ft_check_path(char *path, char **allpath)
{
	int i;

	i = 0;
	if (allpath == NULL)
		return (0);
	while (allpath[i])
	{
		if (ft_strequ(path, allpath[i]))
			return (1);
		i++;
	}
	return (0);
}

char    *ft_get_last_inpath(char *path)
{
	int     i;
	int     k;
	int     j;
	char    *res;

	i = 0;
	k = 0;
	if (path == NULL)
		return (NULL);
	while (path[i])
		i++;
	j = i;
	while (path[i] != '-' && i > 0)
		i--;
	if (i == 0)
	{
		res = ft_strdup(path);
		return (res);
	}
	res = (char*)ft_memalloc(sizeof(char) * (j - i));
	i++;
	while (path[i])
	{
		res[k++] = path[i++];
	}
	return (res);
}

void	ft_modify(char *path, int k)
{
	char	*tmp;
	int	i;

	i = 0;
	tmp = ft_strdup(path);
	ft_strclr(path);
	while (i < k)
	{
		path[i] = tmp[i];
		i++;
	}
}

char    *ft_rm_last_one(char *path)
{
	int i;
	int j;
	int k;
	char *res;

	i = 0;
	while (path[i])
		i++;
	i--;
	k = i;
	while (path[i] != '-' && i >= 0)
		i--;
	res = (char*)ft_memalloc(sizeof(char) * (k - i + 1));
	k = i;
	j = 0;
	if (i == 0)
		return (NULL);
	while (path[i])
	{
		if (path[i] != '-')
			res[j++] = path[i];
		i++;
	}
	ft_modify(path, k);
	return (res);
}

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


char	**ft_findlink(t_ants info, char **allpath)
{
	int 	nb_rooms;
	char	*room;
	char	*path;
	char	*rm;
	char	*rmi;
	char	**tab_rm;
	char	**clonepath;
	int		i;
	int		k;
	int		j;
	int		l;
	int		m;
	int		t;
	int		clonem;

	i = 0;
	m = 0;
	t = 0;
	j = 0;
	l = 0;
	rmi = NULL;
	tab_rm = (char**)ft_memalloc(sizeof(char*) * (200));
	clonepath = (char**)ft_memalloc(sizeof(char*) * (200));
	rm = NULL;
	room = info.start;
	path = info.start;
	if (!(nb_rooms = ft_find_nbroom(&info)))
		return (0);
	k = nb_rooms * 5;
	while (k)
	{
		while (info.tubes[i])
		{
			if (ft_find_room_intube(room, info.tubes[i]) && (!ft_check_ifexist(ft_get_room(room, info.tubes[i]), path)) && (!(rmi && ft_find_room_intube(rmi, info.tubes[i]) && ft_find_room_intube(rm, info.tubes[i]))) && (!ft_check_path(ft_get_room(room, info.tubes[i]), tab_rm)))
			{
							path = ft_strjoin(ft_strjoin(path, "-"), ft_get_room(room, info.tubes[i]));
							room = ft_get_room(room, info.tubes[i]);
							if (ft_strequ(room, info.end))
							{
								if (!ft_check_path(path, allpath))
									allpath[j++] = ft_strdup(path);
								rm = ft_rm_last_one(path);
								room = ft_get_last_inpath(path);
								rmi = ft_get_last_inpath(path);
								i = 0;

				}
			}
			i++;
		}
		i = 0;
		k--;
		if (ft_check_path(path, clonepath))
		{
			m++;
			clonem = m;
			if (ft_strlen(path) == 3)
				m = 1;
			if (ft_strlen(path) == 1)
				m = 0;
			while (m)
			{
				rm = ft_rm_last_one(path);
				ft_putendl("rm");
				m--;
			}
			if (!ft_strequ(rm, info.end) && !ft_check_path(rm, tab_rm)){
				tab_rm[t++] = rm;
			int y;
			y = 0;
			while (tab_rm[y])
			printf("tab_rm[l] %s\n", tab_rm[y++]);}
			ft_putendl("end rm");
			m = clonem;
			room = ft_get_last_inpath(path);
			rmi = ft_get_last_inpath(path);
		}
		else  
		{
			clonepath[l++] = ft_strdup(path);
			m = 0;
		}
	}
	return (allpath);
}


char	**ft_find_path(t_ants info)
{
	char	**conexion;
	char	**allpath;
	int		i;

	i = 0;
	allpath = (char**)ft_memalloc(sizeof(char*) * (500 + 1));
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
	char	**path;

	i = 0;
	//	allpath=0;
	ant_path = ft_createtab(info.nb_ant);
	path = ft_find_path(info);
	while (path[i])
		printf("allpath[i] = %s\n", path[i++]);
}
