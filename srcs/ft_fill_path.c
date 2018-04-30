/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:44:09 by rkrief            #+#    #+#             */
/*   Updated: 2018/04/27 11:34:03 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void		ft_save_path_ifrepeat(t_ants *info, char **clonepath)
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

void		ft_initializeb(t_ants *info, int *i)
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

void		ft_into_the_while(char *tmp, int *i, char **allpath, t_ants *info)
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
			ft_add_and_delete(info, allpath);
			*i = -1;
		}
	}
	else
		ft_strdel(&tmp);
	*i = *i + 1;
}

char		**ft_findlink(t_ants *info, char **allpath)
{
	char	*tmp;
	char	**clonepath;
	int		clonem;
	int		i;

	tmp = NULL;
	ft_initializeb(info, &i);
	clonepath = (char**)ft_memalloc(sizeof(char*) * (200));
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

void		ft_fill_path(t_ants *info)
{
	int		i;
	char	**path;
	char	**allpath;

	i = 0;
	allpath = (char**)ft_memalloc(sizeof(char*) * (500 + 1));
	ft_find_nb_tubes(info);
	ft_find_nbroom(info);
	path = ft_findlink(info, allpath);
	while (path[i])
		printf("allpath[i] = %s\n", path[i++]);
	i = 0;
	while (path[i])
		ft_strdel(&path[i++]);
	ft_memdel((void**)path);
	i = 0;
	while (allpath[i])
		ft_strdel(&allpath[i++]);
	ft_memdel((void**)allpath);
}
