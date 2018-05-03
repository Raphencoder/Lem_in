/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:44:09 by rkrief            #+#    #+#             */
/*   Updated: 2018/05/03 14:15:50 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void		ft_save_path_ifrepeat(t_ants *info, char **clonepath)
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

static void		ft_initializeb(t_ants *info, int *i)
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

static void		ft_into_the_while(char *tmp, int *i, char **p, t_ants *info)
{
	tmp = ft_get_room(info->room, info->tubes_names[*i]);
	if (ft_find_room_intube(info->room, info->tubes_names[*i]) &&
			(!ft_check_ifexist(tmp, info->path)) &&
			(!ft_find_room_intube(info->rm, info->tubes_names[*i])))
	{
		info->path = ft_complete_path(info->path, info->room, *i, *info);
		if (info->room)
			ft_strdel(&info->room);
		info->room = tmp;
		if (ft_strequ(info->room, info->end))
		{
			ft_add_and_delete(info, p);
			*i = -1;
		}
	}
	else
		ft_strdel(&tmp);
	*i = *i + 1;
}

static char		**ft_findlink(t_ants *info, char **allpath)
{
	char	*tmp;
	char	**clonepath;
	int		clonem;
	int		i;

	tmp = NULL;
	ft_initializeb(info, &i);
	clonepath = (char**)ft_memalloc(sizeof(char*) * (info->nb_tubes * 10));
	while (info->k)
	{
		while (info->tubes_names[i])
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

void			ft_fill_path(t_ants *info)
{
	int		i;
	char	**path;
	char	**allpath;

	info->tmp = NULL;
	ft_find_nb_tubes(info);
	allpath = (char**)ft_memalloc(sizeof(char*) * (info->nb_tubes * 10));
	ft_find_nbroom(info);
	path = ft_findlink(info, allpath);
	info->tmpp = path;
	path = ft_sort_paths(info->tmpp);
	i = 0;
	while (path[i])
	{
		info->tmp = path[i];
		path[i++] = ft_sub_path(info->tmp);
		ft_strdel(&info->tmp);
	}
	ft_nextoffind(info, path);
}
