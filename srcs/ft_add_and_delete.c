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
