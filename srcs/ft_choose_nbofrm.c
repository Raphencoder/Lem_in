/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:44:09 by rkrief            #+#    #+#             */
/*   Updated: 2018/04/30 18:12:58 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	ft_choose_nbofrm(int *clonem, t_ants *info)
{
	info->m++;
	while (info->m >= ft_nbrooms_in_path(info->path))
		info->m--;
	*clonem = info->m;
	while (info->m)
	{
		if (info->rm)
			ft_strdel(&info->rm);
		if (ft_nbrooms_in_path(info->path) != 1)
			info->rm = ft_rm_last_one(info->path);
		else
			break ;
		info->m--;
	}
	info->m = *clonem;
	ft_strdel(&info->room);
	info->room = ft_get_last_inpath(info->path);
	if (ft_strequ(info->room, "") || ft_strequ(info->path, ""))
	{
		info->room = info->start;
		info->path = info->start;
	}
}
