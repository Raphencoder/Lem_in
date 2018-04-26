/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:44:09 by rkrief            #+#    #+#             */
/*   Updated: 2018/04/26 12:59:20 by Raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void    ft_move_two(char **tubes)
{
	int i;
	char *clone;

	i = 0;
	while (tubes[i] && tubes[i + 1])
	{
		clone = tubes[i + 1];
		tubes[i + 1] = tubes[i];
		tubes[i++] = clone;
	}

}


void	ft_move_triple(char **tubes)
{
	int i;
	int j;
	char *clone;

	i = 0;
	j = 0;

	while (tubes[i] && tubes[i + 2])
	{
		clone = tubes[i];
		tubes[i] = tubes[i + 2];
		tubes[i + 2] = clone;
		i++;	
	}	
}


void    ft_move_back(char **tubes)
{
	int i;
	int j;
	char *clone;

	i = 0;
	j = 0;
	while (tubes[i])
		i++;
	i--;
	while (j < i)
	{
		clone = tubes[j];
		tubes[j++] = tubes[i];
		tubes[i--] = clone;
	}

}

void    ft_move_tubes(char **tubes)
{
	static int l;

	if (l == 0)
		ft_move_back(tubes);
	if (!(l % 5))
		ft_move_back(tubes);	
	else if (l % 2)
	{
		ft_move_two(tubes);	
		ft_move_triple(tubes);
	}
	else
		ft_move_two(tubes);
	l++;
}


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
		res[k++] = path[i++];
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
	ft_strdel(&tmp);
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
		if (path[i++] != '-')
			res[j++] = path[i - 1];
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
	res = (char*)ft_memalloc(sizeof(char) * (i - j + 1));
	i = 0;
	while (link[j])
		res[i++] = link[j++];
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


void		ft_find_nbroom(t_ants *info)
{
	int	nb_rooms;

	nb_rooms = 0;
	while (info->names[nb_rooms])
		nb_rooms++;
	nb_rooms--;
	if (nb_rooms < 0)
		return ;
	info->nb_room = nb_rooms;
}

char	*ft_remove_ifrepeat(char *rm, int *m,  char *path, char *room)
{
	int clonem;

	*m = *m + 1;
	clonem = *m;
	while ((size_t)*m > (ft_strlen(path) / 2))
		*m = *m - 1;
	while(*m)
	{
		rm = ft_rm_last_one(path);
		*m = *m - 1;
	}
	*m = clonem;
	room = ft_get_last_inpath(path);
	return (room);
}


char 	*ft_complete_path(char *path, char *room, int i, t_ants info)
{
	char *tmp;
	char *tmpp;

	tmpp = ft_get_room(room, info.tubes[i]);
	tmp = path;
	path = (ft_strjoin(tmp, "-"));
	ft_strdel(&tmp);
	tmp = path;
	path = ft_strjoin(tmp, tmpp);
	ft_strdel(&tmp);
	ft_strdel(&tmpp);
	return (path);
}

void	ft_find_nb_tubes(t_ants *info)
{
	int	i;

	i = 0;
	while (info->tubes[i])
		i++;
	i--;
	info->nb_tubes = i;
}

void	ft_add_and_delete(t_ants *info, char **allpath)
{
	if (!ft_check_path(info->path, allpath))
	{		
		allpath[info->j] = ft_strdup(info->path);
		info->j++;
	}
	if (info->rm)
		ft_strdel(&info->rm);
	info->rm = ft_rm_last_one(info->path);
	ft_strdel(&info->rm);
	ft_strdel(&info->room);
	info->room = ft_get_last_inpath(info->path);
	info->rm = ft_get_last_inpath(info->path);
}

void	ft_choose_nbofrm(int *clonem, t_ants *info)
{
	info->m++;
	*clonem = info->m;
	while ((size_t)info->m > (ft_strlen(info->path) / 2))
		info->m--;
	while(info->m)
	{
		if (info->rm)
			ft_strdel(&info->rm);
		info->rm = ft_rm_last_one(info->path);
		info->m--;
	}
	info->m = *clonem;
	ft_strdel(&info->room);
	info->room = ft_get_last_inpath(info->path);

}

void	ft_save_path_ifrepeat(t_ants *info, char **clonepath)
{
	info->nb_repeat++;
	if (info->nb_repeat > info->nb_tubes / 2)
	{
		clonepath[info->l] = ft_strdup(info->path);
		info->l++;
		info->m = 0;
		info->nb_repeat = 0;
	}
}

void	ft_sort_tubes_and_repeat(t_ants *info, int *i)
{
	ft_move_tubes(info->tubes);
	info->k = info->nb_tubes * 10;
	info->nb_tubes--;
	ft_strdel(&info->rm);
	ft_strdel(&info->room);
	info->room = ft_strdup(info->start);
	info->m = 0;
	*i = 0;
}


void	ft_feel_free(t_ants *info, char **clonepath)
{
	int l;

	ft_strdel(&info->room);
	ft_strdel(&info->rm);
	ft_strdel(&info->path);
	l = 0;
	while (clonepath[l])
		ft_strdel(&(clonepath[l++]));
	ft_memdel((void**)clonepath);
	free(clonepath);
}

void	ft_initializeb(t_ants *info, int *i)
{
	*i = 0;
	info->nb_repeat = 0;
	info->j = 0;
	info->l = 0;
	info->m = 0;
	info->rm = NULL;
	info->room = ft_strdup(info->start);
	info->path = ft_strdup(info->start);
	info->k = info->nb_tubes * 10;
}

void	ft_into_the_while(char *tmp, int *i, char **allpath, t_ants *info)
{
	tmp = ft_get_room(info->room, info->tubes[*i]);
	if (ft_find_room_intube(info->room, info->tubes[*i]) && (!ft_check_ifexist(tmp, info->path))
			&& (!ft_find_room_intube(info->rm, info->tubes[*i])))
	{
		info->path = ft_complete_path(info->path, info->room, *i, *info);
		if (info->room)
			ft_strdel(&info->room);
		info->room = tmp;
		if (ft_strequ(info->room, info->end))
		{
			ft_add_and_delete(info, allpath);
			*i = -1;
		}		
	}
	else	
		ft_strdel(&tmp);
	*i = *i + 1;
}

char	**ft_findlink(t_ants *info, char **allpath)
{
	char	*tmp;
	char	**clonepath;
	int	clonem;
	int	i;

	tmp = NULL;
	ft_initializeb(info, &i);
	clonepath = (char**)ft_memalloc(sizeof(char*) * (200));
	while (info->k)
	{
		while (info->tubes[i])
			ft_into_the_while(tmp, &i, allpath, info);
		i = 0;
		info->k--;
		if (ft_check_path(info->path, clonepath))
			ft_choose_nbofrm(&clonem, info);
		else  
			ft_save_path_ifrepeat(info, clonepath);
		if (info->k == 1)
			ft_sort_tubes_and_repeat(info, &i);
	}
	ft_feel_free(info, clonepath);
	return (allpath);
}


char	**ft_find_path(t_ants *info)
{
	char	**allpath;
	int		i;

	i = 0;
	allpath = (char**)ft_memalloc(sizeof(char*) * (500 + 1));
	ft_find_nb_tubes(info);
	ft_find_nbroom(info);
	allpath = ft_findlink(info, allpath);
	return (allpath);	
}


void	ft_fill_path(t_ants *info)
{
	int 	i;
	char	**path;

	i = 0;
	path = ft_find_path(info);
	while (path[i])
		printf("allpath[i] = %s\n", path[i++]);
	i = 0;
	while(path[i])
		ft_strdel(&path[i++]);
	ft_memdel((void**)path);
}
