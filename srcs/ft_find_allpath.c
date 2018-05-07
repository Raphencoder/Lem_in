/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_allpath.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Raphael <raphaelkriefbm@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 10:14:22 by Raphael           #+#    #+#             */
/*   Updated: 2018/05/06 12:16:09 by Raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

char	*ft_complete_pathh(t_ants *info, char *tmp)
{
	ft_putendl(tmp);
	if (ft_strequ(info->rm, NULL))
		info->rm = ft_strdup(tmp);
	else
		{
			ft_putendl("in complete path");
			ft_putstr(info->rm);
			info->rm = ft_strjoin(info->rm, "-");
			info->rm = ft_strjoin(info->rm, tmp);
		}
	return (info->rm);
}

void    ft_add_and_deletee(t_ants *info, char **allpath)
{
	char	*tmp;

	if (!ft_check_path(info->path, allpath))
	{
		allpath[info->j] = ft_strdup(info->path);
		info->j++;
	}
	if (info->rm)
		ft_strdel(&info->rm);
	ft_putendl("INFO->PATH");
	ft_putendl(info->path);
	tmp = ft_rm_last_one(info->path);
	if (!ft_strequ(tmp, info->end))
		info->rm = ft_complete_pathh(info, tmp);
	ft_putstr("info->rm:");
	ft_putendl(info->rm);
	info->room = ft_get_last_inpath(info->path);
}

char	**ft_find_allpath(t_ants *info, char **allpath)
{
	int	i;
	char	*tmpp;
	int	nb_start;
	char	*tmp;
	int k;
	int count;

	i = 0;
	k = 20;
	info->room = ft_strdup(info->start);
	info->path = ft_strdup(info->start);
	info->rm = NULL;
	nb_start = 5;

	while (k)
	{
		while (info->tubes_names[i])
		{
			ft_putchar('\n');
			ft_putendl("TOUR");
			ft_putstr("info->path = ");
			ft_putstr(info->path);
			ft_putstr("  tubesnames[i] = ");
			ft_putstr(info->tubes_names[i]);
			ft_putstr(" |  room = ");
			ft_putstr(info->room);
			ft_putstr(" | info->rm = ");
			ft_putstr(info->rm);
			tmp = ft_get_room(info->room, info->tubes_names[i]);	
		//	if (ft_strequ(tmp, info->start) && info->rm)
		//		start++;
//			if (start > nb_start)
//				break ;	
			if (ft_find_room_intube(info->room,info->tubes_names[i]) &&
					(!ft_check_ifexist(tmp, info->path)) && !ft_check_ifexist(tmp, info->rm))
			{				
				ft_putstr("  IN  |");
				info->path = ft_complete_path(info->path, info->room, i, *info);
				if (info->room)
					ft_strdel(&info->room);
				info->room = tmp;
				ft_putnbr(ft_check_path(info->path, allpath));
				if (!ft_check_path(info->path, allpath))
					count = 0;
				else
					i++;
				ft_putstr("  count = ");
				ft_putnbr(count);
				if (ft_strequ(info->room, info->end))
				{
					ft_putstr("  old path  = ");
			ft_putstr(info->path);
					ft_add_and_deletee(info, allpath);
					ft_putendl("|  new path  = ");
			ft_putstr(info->path);
				}
			}
			else 
			{
				ft_strdel(&tmp); 
				i++;
			}
		}
		i = 0;
		count++;
		if (count >= 2)
{
	tmpp = ft_rm_last_one(info->path);
	if (!ft_strequ(tmpp, info->end))
		info->rm = ft_complete_pathh(info, tmpp);
	ft_putstr("info->rm : ");
	ft_putendl(info->rm);
	info->room = ft_get_last_inpath(info->path);

}			
		k--;
	}
return (NULL);
}
